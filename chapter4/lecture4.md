<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/introduction_to_cv_and_ml">Computer vision and machine learning</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/kzvyagin">Konstantin Zvyagin</a> is licensed under <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY 4.0<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"> <img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"></a></p>

Датасеты для обучения
https://archive.ics.uci.edu/dataset/19/car+evaluation
https://archive.ics.uci.edu/dataset/53/iris

-  Построение вектора признаков изображения.  2
  - 1 Типовые признаки на изображениях. 2
    1.1 Геометрические 6
    - 1.1.1 Особые точки 2
    - 1.1.2 Границы объекта 3
    - 1.1.3 Форма объекта 3
    - 1.1.4 Размеры объекта 3
    1.2 яркостные признаки 3
    - 1.2.1 Экстремумы 4
    - 1.2.2 Частотные признаки 4
    - 1.2.3 Гистограммные признаки 4
    - 1.2.4 Моменты 4
  - 1.3 Текстурные признаки 5
- Классификация.  6
  - Решающие деревья.  6
    - обзор
    - принцип построения деревьев
    - пример построения решающего дерева
  - Поиск объектов по признакам Хаара. 11
    - AdaBoost  17
    - Признаки Хаара 18
    - Проблемы и ограничения каскадов Хаара 19
  - Нейросети. 19
    - Функции активации 22
    - Пример обучения, расчет 25
    - Особенности  обучения 31
  - К ближайших соседей 37
- Методы оценки достоверности работы классификации 33
  - Метрики качества регрессии 33
  - Метрики качества классификации 34


<h1> Построение вектора признаков изображения.<h1>

<h2> Типовые признаки на изображениях.</h2>

<h2>Геометрические.</h2>

<h3> Особые точки.</h3>

Объекты могут иметь свойственные им геометрические особые точки. Например, особыми точками прямоугольника являются четыре его вершины, а отрезка два конца отрезка. Одними из особых точек объектов на изображении являются крайние точки фигуры объекта. районе точки объекта: вершины углов фигуры этого объекта; самая верхняя и самая нижняя точки фигуры объекта относительно координатных осей; левая нижняя, левая верхняя, правая нижняя, правая верхняя точки фигуры объекта; концы линий. особые точки используются для вычисления вторичных признаков.


<h3> Границы объекта </h3>

Края объекта формируют его границы. Границы объекта являются связными контурными линиями объекта, которые характеризуют его форму . Данный признак используется для вычисления таких геометрических признаков, как размер, форма и ориентация объекта. Границы являются вторичными признаками.

<h3>  Форма объекта</h3>

Форма объекта определяется контуром и границами объекта, характеризуется наличием дыр, отношением площади к периметру, вытянутостью, округлостью объекта. Геометрические признаки, определяющие форму объекта, состоят из периметра, площади, минимального и максимального радиусов, углов, степени округленности объекта, кривизны объекта, степени симметрии объекта. Норма является вторичным признаком.

<h3>Размеры объекта</h3>


Размерным признакам можно отнести количество пикселей объекта, его длину, ширину, габариты.


<h2> Яркостные признаки</h2>

Использование данных признаков применимо к цветным, полутоновым и бинарным изображениям. Данные признаки описывают изменения локальной энергии изображения перепады в яркостях пикселей, составляющих изображение. Например, если на изображении присутствует относительно равномерный фон, а на фоне располагается объект с отличающейся от фона яркостью, то в данном случае границы объекта формируются яркостными признаками, так как имеются перепады в уровнях яркостей фона и объекта.



<h3> Экстремумы</h3>

Экстремум это максимальное или минимальное значение пикселя или пикселей на изображении. Если он вычисляется на всем изображении, то это глобальный экстремум, если на области изображения то локальный. Экстремумы являются первичными признаками.


<h3>  Частотные признаки</h3>

Некоторые преобразования, например Фурье, позволяют сформировать частотное представление изображения, по которому можно вычислить частотные признаки. Высокочастотные признаки используются для обнаружения краев и границ, угловые щели используются для определения ориентации. Например, изображение, содержащее несколько параллельных линий с углом ориентации �, даст четкую энергию в частотном пространстве вдоль линии с углом pi + �, проходящей через начало координат преобразования Фурье. ѕоско2льку сначала вычисляется частотное представление изображения, а на частотном пространстве частотные признаки, то они являются вторичными.

<h2> Гистограммные признаки</h2>

Гистограммные признаки являются статистическими и описывают распределение яркости изображения.   этому типу признаков относят среднее значение, стандартное отклонение, искажение, энергию, энтропию. Гистограммные признаки являются вторичными.


<h3> Моменты</h3>

<b>Моменты изображения</b> ( англ. image moments) в компьютерном зрении, обработке изображений и смежных областях — некоторые частные средневзвешенные (момент) интенсивностей пикселей изображения, или функция таких моментов. Как правило, выбираются моменты, имеющие полезные свойства или интерпретации.

В самом общем смысле момент функции — это некая скалярная величина, которая характеризует эту функцию и может быть использована для артикуляции её важных свойств. С математической точки зрения набор моментов является в некотором смысле «проекцией» функции на полиномиальный базис. Он аналогичен преобразованию Фурье, которое представляет из себя проекцию функции на базис из гармонических функций.

Моменты изображения полезны для описания объектов после сегментации. Простые свойства изображения, которые можно найти с помощью моментов, включают в себя площадь (или суммарную интенсивность), геометрический центр и информацию об ориентации. Кроме них в математической статистике давно применяются моменты более высоких порядков, например коэффициент асимметрии и коэффициент эксцесса.


<h2>Текстурные признаки</h2>


Текстуры встречаются на самых разных изображениях, например на изображениях песка, зерна, травы, ткани. Термин "текстура” связан с повторением базовых элементов текстур текселей. Тексель содержит несколько пикселей, расположение которых периодичное, квазипериодичное или случайное. Природные текстуры обычно случайные, в то время как искусственные очень часто периодические. Текстуры могут быть грубыми, тонкими, размытыми, гранулированными, регулярными, нерегулярными, линейными. Текстуры обычно делятся на структурные и стохастические . 

Бывают следующих видов


    • Контраст 
    • Корреляция
    • Угловой момент второго порядка 
    • Сумма дисперсий 
    • Сумма энтропии
    • Энтропия



<h1>Классификация.</h1>


Классификация — распределение данных по параметрам. Например, на вход дается набор людей и нужно решить, кому из них давать кредит, а кому нет. Эту работу может сделать решающее дерево, алгоритм KNN(K ближайших соседей), нейронная сеть и другие. Для этого алгоритму потребуются проанализировать такие фичи как: возраст, платежеспособность, кредитная история и т.д.


<h2>Решающие деревья.</h2>

Дерево решений - это один из самых популярных алгоритмов машинного обучения. Сама концепция появилась достаточно давно и уходит в 1930-1950 года. Начало активного использования решающих деревьев связано с публикациями двух алгоритмов построения решающих деревьев, а именно ID3 и CART. Они были изобретены независимо примерно в одно и то же время (между 1970 и 1980 годами).

Деревья решений используются как для задач классификации, так и для регрессии. Сегодня мы поговорим о классификации.

Прежде чем мы углубимся, зададим себе простой вопрос, почему именно решающие деревья? У нас есть и другие алгоритмы, так почему мы должны выбирать именно деревья решений?

Решающие деревья часто имитирует мышление человеческого уровня, поэтому их так просто понять и сделать некоторые хорошие интерпретации.

Деревья решений фактически позволяют увидеть логику для интерпретации данных (не как алгоритмы черного ящика, такие как NN и т. д.).

Например: если мы классифицируем заявку на получение банковского кредита для клиента, дерево решений может выглядеть следующим образом:
