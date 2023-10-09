#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GunlukGiris {
    char tarih[30];
    char unvan[30];
    char mesaj[30];
    struct GunlukGiris* next;
};

struct GunlukGiris* head = NULL;

void GirisEkleme(const char* tarih, const char* unvan, const char* mesaj) {
    struct GunlukGiris* YeniGiris = (struct GunlukGiris*)malloc(sizeof(struct GunlukGiris));
    strcpy(YeniGiris->tarih, tarih);
    strcpy(YeniGiris->unvan, unvan);
    strcpy(YeniGiris->mesaj, mesaj);
    YeniGiris->next = head;
    head = YeniGiris;
}

void GirisListele() {
    struct GunlukGiris* current = head;
    while (current != NULL) {
        printf("Tarih: %s\n", current->tarih);
        printf("Kimden: %s\n", current->unvan);
        printf("İçerik:\n%s\n", current->mesaj);
        printf("\n");
        current = current->next;
    }
}

void GirisSil(const char* unvan) {
    struct GunlukGiris* current = head;
    struct GunlukGiris* prev = NULL;

    if (current != NULL && strcmp(current->unvan, unvan) == 0) {
        head = current->next;
        free(current);
        return;
    }

    while (current != NULL && strcmp(current->unvan, unvan) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Silinecek tarih bulunamadi.\n");
        return;
    }

    prev->next = current->next;
    free(current);
}

int main() {
    GirisEkleme("2023-10-08", "MERT", "SELAMS");
    GirisEkleme("2023-10-08", "AHMET", "Hİ GUYS");
    GirisListele();
    GirisSil("MERT");
    GirisListele();
    return 0;
}
