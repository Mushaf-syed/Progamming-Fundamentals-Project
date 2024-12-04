#include <stdio.h>
#include<string.h>

void calculate_profit_loss() {
    FILE *dispatched_fp, *returned_fp;
    int dispatched_total = 0, returned_total = 0;
    int add_spent, other_expense;
    int total_quantity=0;

    printf("Enter advertising expense: ");
    scanf("%d", &add_spent);
    printf("Enter other expenses: ");
    scanf("%d", &other_expense);

    dispatched_fp = fopen("dispatched.csv", "r");
    if (dispatched_fp == NULL) {
        printf("Could not open dispatched.csv\n");
        return;
    }

    
    char line[100];
    fgets(line, sizeof(line), dispatched_fp);

    while (fgets(line, sizeof(line), dispatched_fp)) {
        int product_id, price, quantity;
        if (sscanf(line, "%d,%*[^,],%d,%d", &product_id, &price, &quantity) == 3) {
            dispatched_total += price * quantity;
       
        }
        }
       
    fclose(dispatched_fp);
    

    returned_fp = fopen("returned.csv", "r");
    if (returned_fp == NULL) {
        printf("Could not open returned.csv\n");
        return;
    }

   
    fgets(line, sizeof(line), returned_fp);

    while (fgets(line, sizeof(line), returned_fp)) {
        int price, quantity;
        if (sscanf(line, "%d,%d",&price, &quantity) == 2) {
            returned_total += price * quantity;
        }
    }
    fclose(returned_fp);

    // Calculate and print profit or loss
    int net_profit_loss = dispatched_total - returned_total - add_spent - other_expense;

    printf("\n\n");
    printf("Total Dispatched Value: Rs %d\n", dispatched_total);
    printf("Total Returned Value: Rs %d\n", returned_total);
 
    printf("Advertising Expense: Rs %d\n", add_spent);
    printf("Other Expenses: Rs %d\n", other_expense);

    if (net_profit_loss > 0) {
        printf("Profit: Rs %d\n", net_profit_loss);
    } else if (net_profit_loss < 0) {
        printf("Loss: Rs %d\n", -net_profit_loss);
    } else {
        printf("Break-even: No Profit, No Loss.\n");
    }
}

int main() {
    calculate_profit_loss();
    return 0;
}
