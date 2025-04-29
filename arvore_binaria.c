#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node* root;
} ArvoreBinaria;

Node* create_node(char data);
Node* build_tree_recursive(const char** expression);
int is_valid_expression(const char* expression);
ArvoreBinaria* create_tree(const char* expression);
void preorder_traversal(Node* node);
void print_preorder(ArvoreBinaria* tree);
void inorder_traversal(Node* node);
void print_inorder(ArvoreBinaria* tree);
void postorder_traversal(Node* node);
void print_postorder(ArvoreBinaria* tree);
int calculate_height(Node* node);
Node* find_node(Node* root, char value);
int node_height(ArvoreBinaria* tree, char node_value);
int tree_height(Node* node);
void print_tree_recursive(Node* root, int spaces);
void print_tree(ArvoreBinaria* tree);
void free_node(Node* node);
void free_tree(ArvoreBinaria* tree);

Node* create_node(char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* build_tree_recursive(const char** expression) {
    while (**expression == ' ' || **expression == '\t' || **expression == '\n') {
        (*expression)++;
    }
    
    if (**expression == '\0' || **expression == ')') {
        return NULL;
    }
    
    if (**expression == '(') {
        (*expression)++;
        
        while (**expression == ' ' || **expression == '\t' || **expression == '\n') {
            (*expression)++;
        }
        
        if (**expression == ')') {
            (*expression)++;
            return NULL;
        }
        
        char node_value = **expression;
        (*expression)++;
         
        while (**expression == ' ' || **expression == '\t' || **expression == '\n') {
            (*expression)++;
        }
        
        if (**expression == ',') {
            (*expression)++;
        } else {
            fprintf(stderr, "Erro: Esperava-se uma vírgula após o valor do nó.\n");
            return NULL;
        }
        
        Node* node = create_node(node_value);
        
        node->left = build_tree_recursive(expression);
        if (**expression == ',') {
            (*expression)++;
        } else {
            fprintf(stderr, "Erro: Esperava-se uma vírgula entre as subárvores.\n");
            free(node);
            return NULL;
        }
        
        node->right = build_tree_recursive(expression);
        if (**expression == ')') {
            (*expression)++;
            return node;
        } else {
            fprintf(stderr, "Erro: Esperava-se um parêntese de fechamento.\n");
            free(node);
            return NULL;
        }
    }
    
    return NULL;
}

int is_valid_expression(const char* expression) {
    int count = 0;
    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            count++;
        } else if (expression[i] == ')') {
            count--;
            if (count < 0) {
                return 0; 
            }
        }
    }
    
    return count == 0;
}

ArvoreBinaria* create_tree(const char* expression) {
    if (!is_valid_expression(expression)) {
        fprintf(stderr, "invalid\n");
        return NULL;
    }
    
    ArvoreBinaria* tree = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
    if (tree == NULL) {
        fprintf(stderr, "Erro: Falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    
    const char* exp_ptr = expression;
    tree->root = build_tree_recursive(&exp_ptr);
    
    return tree;
}

void preorder_traversal(Node* node) {
    if (node != NULL) {
        printf("%c ", node->data);
        preorder_traversal(node->left);
        preorder_traversal(node->right);
    }
}
void print_preorder(ArvoreBinaria* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("\n");
        return;
    }
    
    preorder_traversal(tree->root);
    printf("\n");
}

void inorder_traversal(Node* node) {
    if (node != NULL) {
        inorder_traversal(node->left);
        printf("%c ", node->data);
        inorder_traversal(node->right);
    }
}

void print_inorder(ArvoreBinaria* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("\n");
        return;
    }
    
    inorder_traversal(tree->root);
    printf("\n");
}

void postorder_traversal(Node* node) {
    if (node != NULL) {
        postorder_traversal(node->left);
        postorder_traversal(node->right);
        printf("%c ", node->data);
    }
}

void print_postorder(ArvoreBinaria* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("\n");
        return;
    }
    
    postorder_traversal(tree->root);
    printf("\n");
}

int get_tree_height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int left_height = get_tree_height(node->left);
    int right_height = get_tree_height(node->right);
    return (left_height > right_height ? left_height : right_height) + 1;
}

int calculate_height(Node* node) {
    if (node == NULL) {
        return -1; 
    }
    
    int left_height = calculate_height(node->left);
    int right_height = calculate_height(node->right);
    
    return (left_height > right_height ? left_height : right_height) + 1;
}
Node* find_node(Node* root, char value) {
    if (root == NULL) {
        return NULL;
    }
    
    if (root->data == value) {
        return root;
    }
    
    Node* found = find_node(root->left, value);
    if (found != NULL) {
        return found;
    }
    
    return find_node(root->right, value);
}

int node_height(ArvoreBinaria* tree, char node_value) {
    if (tree == NULL || tree->root == NULL) {
        return -1;
    }
    
    Node* node = find_node(tree->root, node_value);
    if (node == NULL) {
        return -1; 
    }
    
    return calculate_height(node);
}

int tree_height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    
    int left_height = tree_height(node->left);
    int right_height = tree_height(node->right);
    
    return (left_height > right_height ? left_height : right_height) + 1;
}

void print_tree_recursive(Node* root, int spaces) {
    if (root == NULL)
        return;

    print_tree_recursive(root->right, spaces + 4);

    for (int i = 0; i < spaces; i++)
        printf(" ");
    printf("%c\n", root->data);

    print_tree_recursive(root->left, spaces + 4);
}
void print_tree(ArvoreBinaria* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("\n");
        return;
    }
    
    print_tree_recursive(tree->root, 0);
}
void free_node(Node* node) {
    if (node != NULL) {
        free_node(node->left);
        free_node(node->right);
        free(node);
    }
}

void free_tree(ArvoreBinaria* tree) {
    if (tree != NULL) {
        free_node(tree->root);
        free(tree);
    }
}

int main() {
    ArvoreBinaria* tree = NULL;
    char command[1000];
    char expression[1000];
    char node_value;

    while (1) {
        if (fgets(command, 1000, stdin) == NULL) {
            break;
        }
        
        int len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }
        
        if (strncmp(command, "create", 6) == 0) {
            if (sscanf(command + 6, " %[^\n]", expression) == 1) {
                if (tree != NULL) {
                    free_tree(tree);
                }
                
                tree = create_tree(expression);
                if (tree == NULL) {
                    printf("invalid\n");
                }
            }
        } else if (strcmp(command, "pre") == 0) {
            print_preorder(tree);
        } else if (strcmp(command, "in") == 0) {
            print_inorder(tree);
        } else if (strcmp(command, "post") == 0) {
            print_postorder(tree);
        } else if (strncmp(command, "height", 6) == 0) {
            if (sscanf(command + 6, " %c", &node_value) == 1) {
                int height = node_height(tree, node_value);
                printf("%d\n", height);
            }
        } else if (strcmp(command, "print") == 0) {
            print_tree(tree);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Comando desconhecido.\n");
        }
    }
    if (tree != NULL) {
        free_tree(tree);
    }
    
    return 0;
}