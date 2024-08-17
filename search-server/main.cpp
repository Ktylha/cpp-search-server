#include "paginator.h"
#include "read_input_functions.h"
#include "request_queue.h"
#include "search_server.h"

#include <iostream>

using namespace std;
int main() { 

    try { 
    setlocale(0, "");
    SearchServer search_server("и в на"s); 
    RequestQueue request_queue(search_server);
    search_server.AddDocument(1, "пушистый пёс и модный ошейник"s, DocumentStatus::ACTUAL, { 1, 2 }); 
    search_server.AddDocument(2, "ewaeae awea"s, DocumentStatus::ACTUAL, { 1, 2 }); 
    search_server.AddDocument(3, "изумительныйplayboy"s, DocumentStatus::ACTUAL, { 1, 3, 2 }); 
    search_server.AddDocument(4, "большой пёс скворец"s, DocumentStatus::ACTUAL, { 1, 3, 2, 4 }); 
    search_server.AddDocument(5, "пушистый кот пушистый хвостcc"s, DocumentStatus::ACTUAL, { 7, 2, 7 }); 

    for (int i = 0; i < 1439; ++i) {
        request_queue.AddFindRequest("empty request"s);
    }
    request_queue.AddFindRequest("модный пёс"s);
    request_queue.AddFindRequest("большой пёс"s);
    request_queue.AddFindRequest("кот"s);
    cout << "Общее количество пустых запросов: "s << request_queue.GetNoResultRequests() << endl;

    } 
 
    catch (const invalid_argument& e) { 
        cout << "Error: "s << e.what() << endl; 
    } 
} 