
struct wordstruct {
    char *name;
    char *explaination;
};

/* char *query(char *searchword); */
struct wordstruct *query(char *searchword);

struct wordstruct *queryandhidesearchword(char *searchword);
struct wordstruct *querybyindex(char *searchword);
