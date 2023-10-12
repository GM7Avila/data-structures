// especificações - header
typedef struct float_vector FloatVector;

FloatVector *create(int capacity);
void destroy(FloatVector **vec);
int size(const FloatVector *vec);
int capacity(const FloatVector *vec);
float at(const FloatVector *vec, int index);
float get(const FloatVector *vec, int index);
void append(FloatVector *vec, int index, float val);
void print(const FloatVector *vec);