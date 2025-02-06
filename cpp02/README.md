# 📌 المفاهيم الأساسية في CPP Module 02

## 1. المفاهيم العامة على Fixed Point
- **ما هو Fixed Point؟**
- **لماذا يوجد Fixed Point و Floating Point؟**  
- **كيف يتم تخزين عدد عشري باستخدام Fixed Point؟**  
- **الفرق بين Fixed Point و Floating Point من حيث الأداء والدقة؟**  

## 2. أساسيات C++ المطلوبة في المشروع
### 🔹 الـ Canonical Form (الشكل القانوني)
- **ما معنى Canonical Form في C++؟**  
- **الفرق بين Default Constructor و Copy Constructor؟**  
- **ماذا يفعل Copy Assignment Operator؟**  
- **كيف يجب أن يكون Destructor في الكلاس؟**  

### 🔹 الـ Accessors
- **الفرق بين getter و setter؟**  
- **لماذا `getRawBits()` مكتوب بـ `const`؟**  

### 🔹 الـ Constructors
- **كيف يمكن إنشاء Fixed Point من integer؟**  
- **كيف يتم إنشاء Fixed Point من float؟**  
- **كيف يجب أن يكون copy constructor في هذا الكلاس؟**  

## 3. العمليات الأساسية على Fixed Point
### 🔹 التحويلات (Conversion)
- **كيف نحول Fixed Point إلى `int`؟**  
- **كيف نحول Fixed Point إلى `float`؟**  
- **الفرق بين `toInt()` و `toFloat()`؟**  

### 🔹 الـ Operator Overloading
- **ماذا يفعل `<<` operator في هذا الكلاس؟**  
- **كيف نضيف comparison operators (`<`, `>`, `<=`, `>=`, `==`, `!=`)؟**  
- **كيف نضيف arithmetic operators (`+`, `-`, `*`, `/`)؟**  
- **الفرق بين pre-increment (`++x`) و post-increment (`x++`)؟**  

### 🔹 الـ Static Member Functions
- **كيف يمكن تصميم `min()` و `max()` ليكونا static؟**  
- **لماذا نستخدم static functions في هذا النوع من العمليات؟**  

## 4. المشروع الأخير (BSP)
- **ما هو BSP (Binary Space Partitioning)؟**  
- **كيف يتم استخدام Fixed Point في Point Class؟**  
- **كيف تعمل دالة `bsp()`؟**  
- **كيف تتحقق من أن `bsp()` تعمل بشكل صحيح؟**  

---

## 📌 الأسئلة التي قد تُطرح في الدفاع

### 🟢 أسئلة عن Fixed Point
1. **لماذا استخدمنا `1 << fractionalBits` في الكود؟**  
2. **كيف يتم التخزين في Fixed Point، ولماذا نستخدم `int` كمخزن؟**  
3. **كيف نحدد عدد `bit` المخصص للجزء الصحيح والعشري؟**  
4. **ما المشاكل التي قد تواجهها مع Fixed Point؟**  

### 🔵 أسئلة عن Operator Overloading
5. **كيف تفرق بين member function و non-member function في operator overloading؟**  
6. **لماذا يجب أن يكون `<<` `friend` أو `non-member`؟**  
7. **كيف تعمل `*` و `/` في Fixed Point بشكل صحيح؟**  
8. **ما الفرق بين `a + b` و `a += b` في operator overloading؟**  

### 🟠 أسئلة عن التحويلات
9. **كيف يجب أن يكون `toInt()` مختلفًا عن `toFloat()`؟**  
10. **لماذا `static_cast<int>()` كافٍ في `toInt()`؟**  
11. **لماذا `static_cast<float>()` كافٍ في `toFloat()`؟**  

### 🟣 أسئلة عن C++ Object-Oriented Programming
12. **كيف يقوم `copy constructor` بعمل نسخة صحيحة؟**  
13. **كيف يقوم `operator=` بعمل deep copy وليس shallow copy؟**  
14. **ما الفرق بين `new` و `malloc` في C++؟**  
15. **كيف تحمي Fixed Point من مشاكل الذاكرة؟**  

### 🟡 أسئلة عن الـ BSP
16. **كيف تعمل `bsp()` لتحديد ما إذا كانت النقطة داخل المثلث؟**  
17. **كيف يجب أن يكون `Point` immutable في هذا المشروع؟**  
18. **كيف تتحقق من أن `bsp()` تعمل بشكل صحيح؟**  

---

## 📌 المصطلحات التي قد تُسأل عنها

| **المصطلح** | **التعريف** |
|------------|------------|
| **Fixed Point** | تقنية لتخزين الأعداد العشرية باستخدام عدد ثابت من الـ bits. |
| **Floating Point** | تقنية مرنة لتخزين الأعداد العشرية، حيث تتحرك الفاصلة لتوفير دقة أكبر. |
| **Canonical Form** | مجموعة من القواعد لإنشاء كلاس بطريقة منظمة في C++. |
| **Operator Overloading** | تعديل طريقة عمل الـ Operators مثل `+`, `-`, `*`, `/` في كلاس معين. |
| **Static Function** | دالة تعمل بدون الحاجة إلى إنشاء object من الكلاس. |
| **BSP (Binary Space Partitioning)** | خوارزمية لتقسيم الفضاء لتسهيل الحسابات الجغرافية. |
| **Deep Copy vs Shallow Copy** | **Shallow Copy** ينسخ العنوان فقط، بينما **Deep Copy** ينسخ البيانات بالكامل. |

---

هذا الملخص سيساعدك في التحضير بشكل ممتاز لـ **CPP Module 02**، وحتى لو كان الدفاع صعبًا ستتمكن من الإجابة بسهولة! 🚀🔥

إذا كان لديك أي استفسار، لا تتردد في طرحه! 😃

