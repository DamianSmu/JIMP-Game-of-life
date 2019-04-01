
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>



int main (int argc, char **argv)
{

    char*   path = NULL;
    int     generations = -1;
    int     outstep = 1;
    char*   outpath = argv[0];
    int     outtext = 0;

    while (1)
    {
        static struct option long_options[] =
                {
                        {"path",     required_argument,       0, 'p'},
                        {"generations",  required_argument,       0, 'g'},
                        {"outstep",  required_argument, 0, 's'},
                        {"outpath",  required_argument, 0, 'o'},
                        {"outtext",    no_argument, 0, 't'},
                        {0, 0, 0, 0}
                };

        int option_index = 0;
        int getopt_ret;
        getopt_ret = getopt_long (argc, argv, "p:g:s:o:t",
                         long_options, &option_index);

        if (getopt_ret == -1)
        {
            int missing_arg = 0;
            if(path == NULL)
            {
                printf("Wymagany argument: --path\n");
                missing_arg = 1;
            }
            if(generations == -1)
            {
                printf("Wymagany  argument: --generations\n");
                missing_arg = 1;
            }

            if(missing_arg == 1)
                exit(0);

            break;
        }

        switch (getopt_ret)
        {

            case 'p':
                printf ("option --path with value `%s'\n", optarg);
                path = optarg;
                break;

            case 'g':
                printf ("option --generations with value `%s'\n", optarg);
                char *endptrg;
                generations = strtol (optarg, &endptrg, 10);
                if (*endptrg) {
                    printf("Niewlasciwy argument: --generations %s\n", optarg);
                    exit(0);
                }
                break;

            case 's':
                printf ("option --outstep with value `%s'\n", optarg);
                char *endptrs;
                outstep = strtol (optarg, &endptrs, 10);
                if (*endptrs) {
                    printf("Niewlasciwy argument: --outstep %s\n", optarg);
                    exit(0);
                }
                break;

            case 'o':
                printf ("option --outpath with value `%s'\n", optarg);
                outpath = optarg;
                break;

            case 't':
                puts ("option --outtext\n");
                outtext = 1;
                break;

            case '?':
                break;

            default:
                abort ();
        }
    }

    /* Print any remaining command line arguments (not options). */
    if (optind < argc)
    {
        printf ("Nieobslugiwane argumenty: ");
        while (optind < argc)
            printf ("%s ", argv[optind++]);
        putchar ('\n');
        exit(0);
    }

    exit (0);

}

