using Form = System.Windows.Forms.Form;
using Panel = System.Windows.Forms.Panel;
using EventHandler = System.EventHandler;
using Application = System.Windows.Forms.Application;
using Thread = System.Threading.Thread;
using TimeSpan = System.TimeSpan;
using Button = System.Windows.Forms.Button;
using MessageBox = System.Windows.Forms.MessageBox;
using EventArgs = System.EventArgs;
using Size = System.Drawing.Size;
using AnchorStyles = System.Windows.Forms.AnchorStyles;
using Color = System.Drawing.Color;
using FormBorderStyle = System.Windows.Forms.FormBorderStyle;

public class TicTacMain : System.Windows.Forms.Form
{
    public TicTacMain( )
    {
        const int ButtonSize = 50;
        TicTacPanel ttp = new TicTacPanel( ButtonSize );

        this.Width = ttp.Width + 8;
        this.Height = ttp.Height + 35;
        this.FormBorderStyle = FormBorderStyle.FixedDialog;

        Controls.Add( ttp );
    }

    public static void Main( )
    {
        Application.Run( new TicTacMain( ) );
    }
}


public class TicTacPanel : Panel
{
    private Button[ , ] squares = new Button[ 3, 3 ];
    private TicTacToe t;
    private string computerSide = "O";
    private string humanSide = "X";

    public TicTacPanel( int btnSize )
    {
        int btnWidthHeight = btnSize;
        this.Size = new Size( 3 * btnWidthHeight, 3 * btnWidthHeight );

        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
            {
                squares[ i, j ] = new Button( );
                squares[ i, j ].Left = btnWidthHeight * i;
                squares[ i, j ].Top = btnWidthHeight * j;
                squares[ i, j ].Width = btnWidthHeight;
                squares[ i, j ].Height = btnWidthHeight;

                this.Controls.Add( squares[ i, j ] );
                squares[ i, j ].Click += new EventHandler( OnButtonClick );
            }


        ResetBoard( );
    }

    public void ResetBoard( )
    {
        t = new TicTacToe( );
        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
            {
                squares[ i, j ].Text = "";
                squares[ i, j ].Enabled = true;
            }
    }

    private int gameNum = 0;

    public void DoCompMove( bool thinkAboutIt )
    {
        Best compMove;

        if( thinkAboutIt )
            compMove = t.ChooseMove( TicTacToe.COMPUTER );
        else
        {
            compMove = new Best( 0, gameNum % 3, gameNum / 3 );
            gameNum = ( gameNum + 1 ) % 9;
        }

        MessageBox.Show( " ROW = " + compMove.row +
                    " COL = " + compMove.column );

        squares[ compMove.row, compMove.column ].Text = computerSide;
        squares[ compMove.row, compMove.column ].Enabled = true;
        t.PlayMove( TicTacToe.COMPUTER, compMove.row, compMove.column );
    }

    public bool ResetIfDone( bool condition, string message, bool compMoves )
    {
        if( condition )
        {
            MessageBox.Show( message );
            MessageBox.Show( "Restarting..." );
            ResetBoard( );
            if( compMoves )
            {
                MessageBox.Show( "I go first..." );
                computerSide = "X";
                humanSide = "O";
                DoCompMove( false );
            }
            else
            {
                humanSide = "X";
                computerSide = "O";
                MessageBox.Show( "You go first..." );
            }
        }
        return condition;
    }


    public void OnButtonClick( object sender, EventArgs a )
    {
        ( (Button) sender ).Text = humanSide;
        ( (Button) sender ).Enabled = false;

        for( int i = 0; i < 3; i++ )
            for( int j = 0; j < 3; j++ )
                if( sender == squares[ i, j ] )
                    t.PlayMove( TicTacToe.HUMAN, i, j );

        if( ResetIfDone( t.BoardIsFull( ), "DRAW", true ) )
            return;

        DoCompMove( true );
        ResetIfDone( t.IsAWin( TicTacToe.COMPUTER ), "I WIN!!", true );
        ResetIfDone( t.BoardIsFull( ), "DRAW", false );

        return;
    }

}
