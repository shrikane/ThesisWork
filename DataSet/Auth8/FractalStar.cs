using System;
using System.Drawing;
using System.Collections;
using Form = System.Windows.Forms.Form;
using PaintEventArgs = System.Windows.Forms.PaintEventArgs;
using PaintEventHandler = System.Windows.Forms.PaintEventHandler;
using Application = System.Windows.Forms.Application;
using Graphics = System.Drawing.Graphics;
using Pen = System.Drawing.Pen;
using Color = System.Drawing.Color;
using Thread = System.Threading.Thread;
using TimeSpan = System.TimeSpan;

public class FractalStar : System.Windows.Forms.Form
{
    private static readonly int theSize = 256;
    private static readonly Pen drawingPen = new Pen( new SolidBrush( Color.White ) );

    public FractalStar( )
    {
        //setup form size
        this.Size = new System.Drawing.Size( theSize + 20, theSize + 80 );

        //identify & associate the handler for paint event
        this.Paint += new PaintEventHandler( OnPaint );
    }

    public void OnPaint( object sender, PaintEventArgs e )
    {
        e.Graphics.Clear( Color.Gray );
        DrawSpace( e.Graphics, theSize / 2 + 10, theSize / 2 + 30, theSize );
    }

    public void DrawSpace( Graphics g, int xCenter, int yCenter, int boundingDim )
    {
        int side = boundingDim / 2;

        if( side < 1 )
            return;

        int left = xCenter - side / 2;
        int top = yCenter - side / 2;
        int right = xCenter + side / 2;
        int bottom = yCenter + side / 2;

        DrawSpace( g, left, top, boundingDim / 2 );
        DrawSpace( g, left, bottom, boundingDim / 2 );
        DrawSpace( g, right, top, boundingDim / 2 );
        DrawSpace( g, right, bottom, boundingDim / 2 );

        //******************
        //    ***** Uncomment this section to see the drawing in slow motion 
        //    Thread.Sleep( TimeSpan.FromMilliseconds(100) );
        // ***********/

        g.FillRectangle( drawingPen.Brush, left, top, right - left, bottom - top );
    }

    public static void Main( )
    {
        Application.Run( new FractalStar( ) );
    }
}
