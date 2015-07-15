//http://www.careercup.com/question?id=7894677

/*
You are given N ranges of date offsets when N employees are present in an organization. Something like 

1-4 (i.e. employee will come on 1st, 2nd, 3rd and 4th day ) 
2-6 
8-9 
.. 


1-14 

You have to organize an event on minimum number of days such that each employee can attend the event at least twice. Write an algorithm (there is apparently an O(n) algorithm for this).
*/

int schedule_meetings_twice(int size, int *starts, int*ends) {
        if(size == 0) return 0;
    
        intervalheap iheap(size);
        for(int i=0 ; i<size ; i++)
                iheap.add(new interval(starts[i], ends[i]));

        int total = 2;
        interval *iv = iheap.extract();
        int last1 = iv->end;
        int last2 = iv->end-1;
        delete iv; 

        cout << "at: " << last1 << " and " << last2 << endl;

        while(!iheap.isempty()) {
                interval *iv = iheap.extract();
                if(iv->start > last1) {
                        total+=2;
                        last1 = iv->end;
                        last2 = iv->end-1;

                        cout << "at: " << last1 << " and " << last2 << endl;
                } else if(iv->start > last2) {
                        total+=1;
                        last2 = last1;
                        last1 = iv->end;

                        cout << "at: " << last1 << endl;
                }   
                delete iv; 
        }   

        return total;
}
