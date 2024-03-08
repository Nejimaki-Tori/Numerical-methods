#include <stdio.h>

double arrofalpha[ 1001 ];
double arrofbetta[ 1001 ];
double arrofy[ 1001 ];

double f( int i ) { //вот здесь менять

    if ( ( i >= 21 && i <= 30 ) || ( i >= 41 && i <= 50 ) ) {

        return 0.1;

    }

    else {

        return 0;

    }

}

void alpha( double gamma, int n ) {


    for ( int i = 0 ; i <= n - 1 ; i++ ) {

        if ( i == 0 ) {

            arrofalpha[ i + 1 ] = 0;

        }

        else {

            arrofalpha[ i + 1 ] =( -gamma / ( ( -gamma ) * arrofalpha[ i ] + 2 ) );

        }

    }

}

void betta( double gamma, int n ) {

    for ( int i = 0 ; i <= n - 1 ; i++ ) {

        if ( i == 0 ) {

            arrofbetta[ i + 1 ] = f( 0 );

        }

        else {

            arrofbetta[ i + 1 ] = ( ( f( i ) - ( -gamma ) * arrofbetta[ i ] ) / ( ( -gamma ) * arrofalpha[ i ]  + 2 ) );

        }

    }

}

void y( int i, int n ) {

    if ( i == 0 || i == n ) {

        arrofy[ i ] = f( i );

    }

    else {

        arrofy[ i ] = ( arrofalpha[ i + 1 ] * arrofy[ i + 1 ] + arrofbetta[ i + 1 ] );

    }

}

int main() {

    double g[ 3 ] = { 0.5, 0.75, 1 };
    int n[ 2 ] = { 100, 1000 };

    for ( int i = 0; i < 3; i++ ) {

        for ( int j = 0; j < 2; j++ ) {

            printf( "\nn = %d gamma = %lf \n", n[ j ], g[ i ] );

            alpha( g[ i ], n[ j ] );
            betta( g[ i ], n[ j ] );

            for ( int k = n[ j ]; k >= 0; k-- ){

                y ( k, n[ j ] );

            }

            for ( int k = 0 ; k <= n[ j ] ; k++ ) {

                printf( "y( %d ) = %lf\n", k, arrofy[ k ] );

            }

        }

    }

}
