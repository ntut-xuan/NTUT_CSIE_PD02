#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define ShapeText(TYPE) char name[10]; double (*perimeter)(struct TYPE*); double (*area)(struct TYPE*);

typedef struct shape_s {
    ShapeText(shape_s);
} Shape_t;

typedef struct circle_s {
    ShapeText(circle_s);
    double radius;
} Circle_t;

typedef struct rectangle_s {
    ShapeText(rectangle_s);
    double len;
    double width;
} Rectangle_t;

typedef struct square_s {
    ShapeText(square_s);
    double edge;
} Square_t;

typedef struct triangle_s {
    ShapeText(triangle_s);
    double a, b, c;
} Triangle_t;

double CirclePerimeter(Circle_t* circle){
    return 2 * 3.14 * circle->radius;
}

double ShapePerimeter(Shape_t* shape){
    return 0;
}

double SquarePerimeter(Square_t* square){
    return 4 * square->edge;
}

double TrianglePerimeter(Triangle_t* triangle){
    return triangle->a + triangle->b + triangle->c;
}

double RectanglePerimeter(Rectangle_t* rectangle){
    return 2 * (rectangle->len + rectangle->width);
}

int main(){
    int n;
    scanf("%d", &n);
    Shape_t* sh[n];
    double total = 0;
    for(int i = 0; i < n; i++){
        char c;
        scanf(" %c", &c);
        if(c == 'T'){
        	sh[i] = malloc(sizeof(Triangle_t));
			scanf("%lf %lf %lf", &(((Triangle_t*)sh[i])->a), &(((Triangle_t*)sh[i])->b), &(((Triangle_t*)sh[i])->c));
			((Triangle_t*)sh[i])->perimeter = TrianglePerimeter;
		}
		if(c == 'S'){
        	sh[i] = malloc(sizeof(Square_t));
			scanf("%lf", &(((Square_t*)sh[i])->edge));
			((Square_t*)sh[i])->perimeter = SquarePerimeter;
		}
		if(c == 'C'){
        	sh[i] = malloc(sizeof(Circle_t));
			scanf("%lf", &(((Circle_t*)sh[i])->radius));
			((Circle_t*)sh[i])->perimeter = CirclePerimeter;
		}
		if(c == 'R'){
			sh[i] = malloc(sizeof(Rectangle_t));
			scanf("%lf %lf", &(((Rectangle_t*)sh[i])->len), &(((Rectangle_t*)sh[i])->width));
			((Rectangle_t*)sh[i])->perimeter = RectanglePerimeter;
		}
    }
    for(int i = 0; i < n; i++){
    	total += (sh[i]->perimeter(sh[i]));
    	printf("%.2f\n", sh[i]->perimeter(sh[i]));
	}
    printf("%.2f\n", total);
}
