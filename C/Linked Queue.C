#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    char data[20];
    int dist;
    struct ListNode* link;
};

// 노드 생성 함수
struct ListNode* create_node(const char* name, int dist) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    strcpy(new_node->data, name);
    new_node->dist = dist;
    new_node->link = NULL;
    return new_node;
}

// 노드 삽입 함수
void insert_node(struct ListNode** head, struct ListNode* prev, struct ListNode* new_node, int new_dist) {
    if (prev != NULL) {
        new_node->dist = new_dist;
        new_node->link = prev->link;
        prev->link = new_node;
    }
    else {
        new_node->link = *head;
        *head = new_node;
    }
}

// 노드 삭제 함수
void remove_node(struct ListNode** head, struct ListNode* prev, struct ListNode* to_remove, int new_dist) {
    if (prev != NULL) {
        prev->link = to_remove->link;
        free(to_remove);
    }
    else {
        *head = to_remove->link;
        free(to_remove);
    }
}

// 역 이름으로 노드 검색 함수
struct ListNode* search(struct ListNode* head, const char* name) {
    struct ListNode* current = head;
    while (current != NULL) {
        if (strcmp(current->data, name) == 0) {
            return current;
        }
        current = current->link;
    }
    return NULL;
}

// 출발역부터 도착역까지의 총 시간 출력 함수
void Time(struct ListNode* head, struct ListNode* start, struct ListNode* end) {
    int total_time = 0;
    struct ListNode* current = start;
    while (current != end) {
        total_time += current->dist;
        current = current->link;
    }
    printf("Total time from %s to %s: %d minutes\n", start->data, end->data, total_time);
}

// 전체 노선 출력 함수
void display(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%s-(%d분)->", current->data, current->dist);
        current = current->link;
    }
    printf("끝\n");
}

int main() {
    struct ListNode* subway = NULL;

    // 초기 지하철 노선 설정
    struct ListNode* jeju_airport = create_node("제주공항역", 20);
    struct ListNode* aewol = create_node("애월역", 40);
    struct ListNode* seogwipo = create_node("서귀포역", 30);
    struct ListNode* seongsan = create_node("성산역", 30);

    subway = jeju_airport;
    jeju_airport->link = aewol;
    aewol->link = seogwipo;
    seogwipo->link = seongsan;

    // 초기 노선 출력
    printf("Initial Subway Route:\n");
    display(subway);

    // 애월역에서 성산역까지의 소요시간 출력
    Time(subway, aewol, seongsan);

    // 모슬포역 삽입
    struct ListNode* moseulpo = create_node("모슬포역", 30);
    struct ListNode* prev = search(subway, "애월역");
    insert_node(&subway, prev, moseulpo, 30);

    // 노선 업데이트 후 출력
    printf("Subway Route After Inserting Moseulpo Station:\n");
    display(subway);

    // 애월역에서 성산역까지의 소요시간 출력
    Time(subway, aewol, seongsan);

    // 모슬포역 제거
    prev = search(subway, "애월역");
    struct ListNode* to_remove = search(subway, "모슬포역");
    remove_node(&subway, prev, to_remove, 40);

    // 노선 업데이트 후 출력
    printf("Subway Route After Removing Moseulpo Station:\n");
    display(subway);

    free(jeju_airport);
    free(aewol);
    free(seogwipo);
    free(seongsan);
    free(moseulpo);

    return 0;
}
