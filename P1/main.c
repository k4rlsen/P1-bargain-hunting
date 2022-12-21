#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct {
    char name[30];
    double cost;
} product_t;


typedef struct node_t {
    product_t item;
    struct node_t* next;
} node_t;

typedef struct {
    node_t* head;
} tree_t;
int products();
void add_product(tree_t* list, char* name, double cost);
void deallocate_list(tree_t* list);
void print_products(tree_t* list);
 int main()
{
     tree_t list_of_items = {NULL};
    char name[30];
    double cost;

    printf("Welcome to the price compare program here you can compare dairy products\n"
           "from Netto, Rema 1000, Spar, and Aldi. There is exactly 12 products\n"
           "these are milk, cheese, yogurt, butter, margarine, butter-cheese, ice-cream,\n"
           "cream, and mozzarella. After looking at the products you have the option to add it to a shopping list\n"
           "to go to the shopping list type sl (do keep in mind you can't go back to looking at the products after)\n");

        products();
    printf("Here you can add items to a shopping list, to do so write the name of the product"
           "\nand the cost (to end your shopping list type end 0)\n");

    while(1)
    {
        printf("Input name and cost ->\n");
        scanf("%s %lf", name, &cost);
        if(strcmp(name, "end") == 0)
        {
            print_products(&list_of_items);
            deallocate_list(&list_of_items);
            exit(EXIT_SUCCESS);
        }
        else {
            add_product(&list_of_items, name, cost);
        }
    }
    deallocate_list(&list_of_items);
    return 0;

    }

int products(){
    char product[30];

   while (1){
       printf("\nHere you can write the product from the dairy aisle you want the price of -> ");
       scanf(" %s",product);

       if (strcmp(product,"milk")==0){
           printf("Milk cost 17 kr in Netto,\nMilk cost 14 kr in Rema 1000,\n"
                  "Milk cost 11 kr in Spar,\nMilk cost 18 kr in Aldi,\n");
       }
       else if (strcmp(product,"cheese")==0){
           printf("Cheese cost 12 kr in Netto,\nCheese cost 19 kr in Rema 1000,\n"
                  "Cheese cost 15 kr in Spar,\nCheese cost 14 kr in Aldi,\n");
       }
       else if (strcmp(product,"yogurt")==0){
           printf("Yogurt cost 14 kr in Netto,\nYogurt cost 11 kr in Rema 1000,\n"
                  "Yogurt cost 15 kr in Spar,\nYogurt cost 13 kr in Aldi,\n");
       }
       else if (strcmp(product,"butter")==0){
           printf("Butter cost 12 kr in Netto,\nButter cost 18 kr in Rema 1000,\n"
                  "Butter cost 14 kr in Spar,\nButter cost 10 kr in Aldi,\n");
       }
       else if (strcmp(product,"margarine")==0){
           printf("Margarine cost 12 kr in Netto,\nMargarine cost 16 kr in Rema 1000,\n"
                  "Margarine cost 18 kr in Spar,\nMargarine cost 21 kr in Aldi,\n");
       }
       else if (strcmp(product,"butter-cheese")==0){
           printf("Butter cheese cost 12 kr in Netto,\nButter cheese cost 14 kr in Rema 1000,\n"
                  "Butter cheese cost 18 kr in Spar,\nButter cheese cost 15 kr in Aldi,\n");
       }
       else if (strcmp(product,"ice-cream")==0){
           printf("Ice cream cost 30 kr in Netto,\nIce cream cost 27 kr in Rema 1000,\n"
                  "Ice cream cost 29 kr in Spar,\nIce cream cost 25 kr in Aldi,\n");
       }
       else if (strcmp(product,"cream")==0){
           printf("Cream cost 15 kr in Netto,\ncream Cost 16 kr in Rema 1000,\n"
                  "Cream cost 22 kr in Spar,\nCream cost 17 kr in Aldi,\n");
       }
       else if (strcmp(product,"mozzarella")==0){
           printf("Mozzarella cost 25 kr in Netto,\nMozzarella cost 27 kr in Rema 1000,\n"
                  "Mozzarella cost 13 kr in Spar,\nMozzarella cost 23 kr in Aldi,\n");
       }
       else if(strcmp(product, "sl") == 0){
           break;
       }
       else {
           printf("This product is either not a dairy product\n"
                  " or has either not been taken into account or spelled wrong");
       }
   }
}


void add_product(tree_t* list, char* name, double cost)
{

    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->next = list->head;
    new_node->item.cost = cost;
    strcpy(new_node->item.name, name);
    list->head = new_node;
}



void deallocate_list(tree_t* list)
{
    node_t* current = list->head;
    while(current != NULL)
    {

        node_t* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}

void print_products(tree_t* list)
{
    node_t* current = list->head;
    while(current != NULL)
    {
        printf("%s %lf\n", current->item.name, current->item.cost);
        current = current->next;
    }
}