#define MAX 100

class Queue {
private:
    int q[MAX];
    int f, b;
public:
    Queue() {
        f=b=-1;
    }
    void enqueue(int x);
    int dequeue();
    int isEmpty();
    int isFull();
    friend void *reader(queue *);
    friend void *writer(queue *);
};

int Queue::isFull() {
    if (b == MAX-1)
        return 1;
    return 0;
}

int Queue::isEmpty() {
    if (f==-1 && b==-1)
        return 1;
    return 0;
}

void Queue::enqueue(int x) {
    if (!isFull()) {
        if(isEmpty()) {
            f = b = 0;
            q[0] = x;
        }
        q[++b] = x;
    }
    else {
        //throw exception
    }
}

int Queue::dequeue() {
    int x;
    if (!isEmpty()) {
        x = q[f++];
        if(f>b)
            f = b = -1;
    }
    else
        //throw exception
}

pthread_mutex_t queue_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notFull = PTHREAD_COND_INITIALIZER;
pthread_cond_t notEmpty = PTHREAD_COND_INITIALIZER;

void * reader(queue *Q) {
    while(1) {
        pthread_mutex_lock(queue_lock);            
            /*
            if (no exception in x = Q->dequeue())
                cout << "Reader consumed : " << x << endl;                
            */        
			while(isEmpty())
				pthread_cond_wait(&notEmpty, &mutex);
			int x = Q->dequeue();
			pthread_cond_signal(&notFull);

        pthread_mutex_unlock(queue_lock);
        sleep(1000);
    }
}

void * writer(queue *Q) {

    while(1) {
        pthread_mutex_lock(queue_lock);
				/*
            if (no exception in Q->enqueue(x)) {
                cout << "Enter x : " << endl;
                cin >> x;
            }*/
			while (isFull())
				  pthread_cond_wait(&notFull, &mutex);
            cout << "Enter x : " << endl;
            cin >> x;
			Q->enqueue(x);
			pthread_cond_signal(&notEmpty);	
        pthread_mutex_unlock(queue_lock);
        sleep(1000);
    }
}

int main() {
    pthread_t r, w;
    queue Q;
    pthread_create(&r, NULL, &reader, &Q);
    pthread_create(&w, NULL, &writer, &Q);
    
    pthread_join(&r, NULL);
    pthread_join(&w, NULL);
}
