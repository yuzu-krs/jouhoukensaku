#include <stdio.h>
#include <mecab.h>

int main() {
    mecab_t *mecab;
    const mecab_node_t *node;
    const char *input = "すもももももももものうち";

    mecab = mecab_new2("");
    if (!mecab) {
        fprintf(stderr, "Unable to initialize Mecab\n");
        return 1;
    }

    node = mecab_sparse_tonode(mecab, input);
    for (; node; node = node->next) {
        if (node->stat != MECAB_BOS_NODE && node->stat != MECAB_EOS_NODE) {
            printf("%.*s\t%s\n", node->length, node->surface, node->feature);
        }
    }

    mecab_destroy(mecab);

    return 0;
}
