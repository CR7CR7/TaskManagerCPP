

---

# **TaskManagerCPP**

Лек и модулен C++ backend за управление на задачи, изграден върху **Boost.Beast**, **SQLite3** и **C++17**.  
Проектът демонстрира как се създава минималистичен HTTP сървър, който обработва заявки, съхранява данни в база и предоставя JSON API.

---

## ✨ **Features**
- **HTTP сървър** с Boost.Beast  
- **SQLite3 база** за съхранение на задачи  
- **JSON API** чрез *nlohmann::json*  
- **Модулна архитектура**: `Server`, `Router`, `Database`, `Task`  
- **Unit тестове** с Catch2  
- **CMake + vcpkg** за управление на зависимости  
- **Cross‑platform** (Windows / Linux)

---

## 📁 **Project Structure**

```
TaskManagerCPP/
│
├── src/
│   ├── main.cpp          # Entry point – стартира HTTP сървъра
│   ├── server.cpp        # Boost.Beast listener + обработка на заявки
│   ├── router.cpp        # Маршрутизация на HTTP пътища
│   ├── database.cpp      # SQLite CRUD операции
│   ├── task.cpp          # Модел на Task
│   ├── *.h               # Header файлове
│
├── tests/
│   └── test_tasks.cpp    # Unit тестове с Catch2
│
├── CMakeLists.txt
└── README.md
```

---

## 🔧 **Dependencies (via vcpkg)**

Проектът използва следните пакети:

- `boost-beast`
- `boost-system`
- `boost-thread`
- `sqlite3`
- `catch2`
- `nlohmann-json`

Инсталация:

```bash
vcpkg install boost-beast:x64-windows boost-system:x64-windows boost-thread:x64-windows sqlite3:x64-windows catch2:x64-windows nlohmann-json:x64-windows
```

---

## 🛠 **Build (Windows + vcpkg)**

```bash
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows
cmake --build .
```

---

## 🚀 **Run**

```bash
./build/Debug/TaskManagerCPP.exe
```

Сървърът стартира на конфигурирания порт (виж `main.cpp`).

---

## 🧪 **Run Tests**

```bash
./build/Debug/TaskManagerTests.exe
```

---

## 📡 **API Endpoints**

### `GET /tasks`
Връща всички задачи.

### `GET /tasks/{id}`
Връща конкретна задача.

### `POST /tasks`
Създава нова задача.

**Body:**
```json
{
  "title": "Buy milk",
  "description": "2 liters",
  "completed": false
}
```

### `PUT /tasks/{id}`
Обновява задача.

### `DELETE /tasks/{id}`
Изтрива задача.

---

## 🧱 **Architecture Overview**

- **Server**  
  Приема TCP връзки и чете HTTP заявки.

- **Router**  
  Разпределя заявките по пътища и извиква съответните handler-и.

- **Database**  
  Работи със SQLite и изпълнява CRUD операции.

- **Task**  
  Представлява модел на данните.

---

## 📌 **Why This Project Exists**

TaskManagerCPP е учебен пример за:

- работа с Boost.Beast  
- изграждане на HTTP API на C++  
- интеграция със SQLite  
- модулна архитектура  
- unit тестове  
- CMake + vcpkg workflow  

Подходящ е за начинаещи и напреднали, които искат да видят реален backend на C++.

---

## 🚧 **Future Improvements**
- Добавяне на async обработка (Boost.Asio coroutines)
- Поддръжка на PATCH заявки
- JWT authentication
- Logging (spdlog)
- Docker контейнеризация
- REST API документация (OpenAPI/Swagger)

---

## 🤝 **Contributing**

Pull requests са добре дошли.  
За големи промени – отворете issue, за да обсъдим идеята.

---

## 📄 **License**

MIT License.

---
