using Form = System.Windows.Forms.Form;
using PaintEventArgs = System.Windows.Forms.PaintEventArgs;
using PaintEventHandler = System.Windows.Forms.PaintEventHandler;
using Application = System.Windows.Forms.Application;
using Graphics = System.Drawing.Graphics;
using Pen = System.Drawing.Pen;
using Color = System.Drawing.Color;
using Thread = System.Threading.Thread;
using TimeSpan = System.TimeSpan;

public class Ruler : System.Windows.Forms.Form
{
    //how to do it using static
    private static readonly int theSize = 511;
    private static readonly Pen drawingPen = new Pen( Color.Black );

    public Ruler( )
    {
        //setup form size
        this.Size = new System.Drawing.Size( theSize + 20, 110 );

        //identify & associate the handler for paint event
        this.Paint += new PaintEventHandler( OnPaint );
    }

    public void OnPaint( object sender, PaintEventArgs e )
    {
        drawRuler( e.Graphics, 10, theSize - 1 + 10, 8 );
    }

    private void drawRuler( Graphics g, int left, int right, int level )
    {
        if( level < 1 )
            return;

        int mid = ( left + right ) / 2;

        /******************
            ***** Uncomment this section to see the drawing in slow motion
            Thread.Sleep( TimeSpan.FromMilliseconds(100) );
        ***********/
        g.DrawLine( drawingPen, mid, 80, mid, 80 - level * 5 );

        drawRuler( g, left, mid - 1, level - 1 );
        drawRuler( g, mid + 1, right, level - 1 );
    }

    public static void Main( string[ ] args )
    {
        Application.Run( new Ruler( ) );
    }
}
