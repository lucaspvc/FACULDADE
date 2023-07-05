#include <plstream.h>

#ifdef PL_USE_NAMESPACE
using namespace std;
#endif

class x00 {
public:
    x00( int, char ** );

private:
    // Class data
    plstream         *pls;

    static const int NSIZE;
};

const int x00::NSIZE = 101;

x00::x00( int argc, char **argv )
{
    PLFLT x[NSIZE], y[NSIZE];
    PLFLT xmin = 0., xmax = 1., ymin = 0., ymax = 100.;
    int   i;

    // Prepare data to be plotted.
    for ( i = 0; i < NSIZE; i++ )
    {
        x[i] = (PLFLT) ( i ) / (PLFLT) ( NSIZE - 1 );
        y[i] = ymax * x[i] * x[i];
    }

    pls = new plstream();

    // Parse and process command line arguments
    pls->parseopts( &argc, argv, PL_PARSE_FULL );

    // Initialize plplot
    pls->init();

    // Create a labelled box to hold the plot.
    pls->env( xmin, xmax, ymin, ymax, 0, 0 );
    pls->lab( "x", "y=100 x#u2#d", "Simple PLplot demo of a 2D line plot" );

    // Plot the data that was prepared above.
    pls->line( NSIZE, x, y );


    // In C++ we don't call plend() to close PLplot library
    // this is handled by the destructor
    delete pls;
}

int main( int argc, char ** argv )
{
    x00 *x = new x00( argc, argv );
    delete x;
}