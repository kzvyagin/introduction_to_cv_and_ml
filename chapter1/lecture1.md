<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://github.com/introduction_to_cv_and_ml">Computer vision and machine learning</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://github.com/kzvyagin">Konstantin Zvyagin</a> is licensed under <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY 4.0<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"> <img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"></a></p>

<h1>Введение </h1>
Добрый день! Сегодня мы будем обсуждать современное направление  развития информационных технологий. А именно цифровую обработку изображений и машинное обучение. 
Вы, наверное, спросите, почему две темы в одном курсе? Ответ на этот вопрос прост, в современных информационных технологиях обработка изображений неотделима от машинного обучения. Пример тому, существующий сегодня новый термин, вычислительная фотография, которой чаще все объясняется, как увеличение характеристик цифровой камеры за счет алгоритмов и способов обработки изображений. Вычислительная фотография присутствует в каждом смартфоне. Очевидно, что невозможно установить в смартфон оптику как у цифрового фотоаппарата, однако качество фотографий смартфона давно сравнялись с профессиональными зеркалками и даже превзошло некоторые из них. Особенно это касается съемки в ночное время, стабилизации изображение и фотографии движущихся объектов. Такой прорыв технологий стал доступным благодаря цифровой обработки изображений и машинному обучению.

Определим термин <b>обработка изображений</b> — это процедура обработки данных <i>(файла цифрового изображения)</i> с использованием компьютера с помощью алгоритма или набора алгоритмов. Термин <b>Машинное обучение</b> (МО) — это область искусственного интеллекта, занимающаяся изучением и применением алгоритмов, которые способны автоматически выявить закономерности в данных и/или преобразовать их в самостоятельную исполняемую модель или функцию (термин алгоритм не употребляется, по причине нечеткости правил в результирующей функции, модели).

 <b>Компьютерное зрение</b> (Computer Vision, CV) — , в том числе машинное зрение (Machine Vision, MV) – это автоматическая фиксация и обработка изображений, как неподвижных, так и движущихся объектов при помощи компьютерных средств. В России также используется термин «техническое зрение».

 <h2>Компьютерное зрение</h2>

 Технологии компьютерного зрения позволяют в сегодняшних реалиях сделать жизнь и бизнес проще, дешевле, безопаснее. По оценкам разных экспертов этот рынок будет двигаться в ближайшие годы только в сторону роста, что и позволяет развиваться соответствующим технологиям, как в сторону производительности, так и качества. Одним из наиболее востребованных разделов является Object Detection (обнаружение объектов) – определение объекта на изображении или в видео потоке.
 
 В сфере распознавания объектов случился внушительный прорыв: За последние пять лет улучшились следующие области:
- развились принципы обучения нейросетей, а именно их ускорение в математическом плане, 
- появились новые архитектурные решения, как по организации нейросетей, так в классических методах машинного обучения; 
- произошел заметный положительный сдвиг в точности распознавания объектов на открытых наборах данных — от от 70 до 98% точности, 
- появились аппаратные ускорители для нейросетей, 
- появились новые подходы в машинном обучении и в особенности в части сверточных нейросетей.

Со многими задачами сейчас алгоритмы машинного обучения и нейросети работают лучше, чем люди (не точнее, но без усталости и необходимости иногда отвлечься от рутинной задачи). Хотя до сих пор мы не можем улучшить по точности результат работы человека, получаемый с помощью обычного, не компьютерного зрения (например, при просмотре термокарт специалистом или КТ-снимков доктором). 

Технология облегчает ежедневные задачи и, разумеется, стремится однажды увидеть что-то за гранью человеческого восприятия. Прогнозы оптимистичные, рынок растет и по оценкам экспертов в ближайшие 5 лет ожидается его расширение еще в 1,5 раза. На вопрос о сферах применения компьютерного зрения и машинного обучения можно ответить, что оно может использоваться везде, где есть какие-либо изображения.

По оценкам Grand View Research, рынок систем компьютерного зрения к 2027 году достигнет $19 млрд. Вероятно, сейчас у многих людей это направление ИИ ассоциируется с системами распознавания лиц. Но, по данным тех же аналитиков, в 2019-м больше 50% рынка систем Computer Vision приходилось на решения для промышленности.

Например, недавно RDL by red_mad_robot совместно с компанией «Полиметалл» закончили внедрение системы на основе компьютерного зрения на перерабатывающем предприятии.

<h2>Где применяют компьютерное зрение</h2>

Наиболее частыми потребителями этой технологии на сегодняшний день являются ритейл (например, сеть Лента или Пятерочка), производство и медицина. Где-то машинное зрение помогает оценить действия работников, где-то борется с мошенничеством, а где-то контролирует качество и склады. 

О медицине лучше сказать отдельно: в связи с пандемией применение машинного зрения в этой области заиграло новыми красками. К примеру, делается очень много снимков легких, следовательно, заметно выросла потребность в разгрузке врачей и ускорении обработки снимков. 

Теперь пройдемся по задачам, которые ставятся в каждой из этих областей.

<h3><i>Ритейл - золотая жила для компьютерного зрения и  машинного обучения</i></h3>

![Торговый центр](https://raw.githubusercontent.com/kzvyagin/introduction_to_cv_and_ml/main/chapter1/images/1.png)


Сама специфика отрасли и переход к открытым раскладкам вынуждают ритейлеров ставить как можно больше камер для борьбы с теми, кто портит или пытается украсть товар. С точки зрения набора данных ритейл — самая подходящая область, где необходимо не только записывать данные, но и хранить их.

В этой отрасли довольно много коробочных решений, которые предлагаются как готовые к внедрению на любую систему видеонаблюдения. В первую очередь они касаются подсчета покупателей и таких несложных действий, как мониторинг очередей. Среди любопытных проектов в области машинного зрения можно назвать силовые карты интереса, которые анализируют места, где покупатели чаще проходят или останавливаются. Это касается не только торговых залов, но и таких больших помещений, как торговые центры и витрины в них. Разумеется, ритейлеры стремятся облегчить и ускорить работу мерчендайзеров.

Офлайн-ритейлеры крайне заинтересованы в том, чтобы понимать своего покупателя так же хорошо, как интернет-магазины. Не секрет, что машинное обучение, внедренное в интернет-магазинах и предлагающее своеобразный upsale к корзине, повышает доходы онлайн-магазинов. Внедрение идентификации клиентов, зарегистрированных в системах лояльности, в зале позволяет офлайн-ритейлерам персонифицировать свои предложения ничуть не хуже: они могут предлагать что-то индивидуализированное с учетом портрета конкретного клиента и истории его покупок.

Также машинное зрение по-прежнему применяется для распознавания людей, которых служба безопасности магазина не хочет видеть на своей территории: их поведение кажется подозрительным или они уже были замечены в шоп-лифтинге или порче товара.

<h3><i>Промышленность</i></h3>

![Промышленный пейзаж](https://raw.githubusercontent.com/kzvyagin/introduction_to_cv_and_ml/main/chapter1/images/2.png)

Еще одна область, где часто применяются технологии машинного зрения — это производство. В первую очередь они используются для автоматизации рутинных действий, особенно в области распознавания дефектов непосредственно на конвейере или оценки сразу после производства.

Особенность в том, что Машина не устает, а обученная различать дефекты нейросеть не нуждается в отпуске или смене места работы.

<b>Оценка брака.</b> На производствах есть модели-помощники, упрощающие работу оценщиков брака, а также модели для полностью автоматической сортировки, где нежелательные детали просто скидываются с конвейера. В возможностях экономии многое зависит от цены потерь: от того, насколько мы хотим быть уверены, что ни одна годная деталь не уйдет по ошибке в брак. Нейросети на производстве, как правило, не достигают 100% точности и уступают ручному отбору, но не знают усталости и принимают решения быстрее.

<b>Контроль.</b> Еще одна популярная область задач, где компьютерное зрение помогает производству, это контроль соблюдения норм. Часто на предприятиях требуется подтверждение того, что сотрудник действует в точности по инструкции, например, убирает руку за спину, если это предусмотрено при определенных работах со щитком, встает на резиновый коврик и так далее. Речь идет о каких-то мелочах, которые легко проверить и цена которых в случае нарушения — человеческая жизнь. С помощью камер и нейросетей мы можем отследить, надели ли сотрудники необходимые средства защиты, не нужно ли заблокировать им доступ к чему-либо в случае нарушения условий, не пересекают ли они предусмотренные линии и соблюдают ли установленную дистанцию до опасных объектов. Иногда речь идет о простом соблюдении определенных регламентов: на многих предприятиях есть определенные чек-листы, которым необходимо четко следовать, чтобы не пропустить какие-то малозначительные, но важные повторяющиеся действия, выполнение которых приводит к большой экономии на издержках. 

Задачи по борьбе с воровством, подложными деталями на конвейере, неправильным перемещением товара по складу — тоже достаточно распространенная область применения машинного зрения.

<b>Склад и логистика.</b> На уровне распознавания этикеток существует достаточно много коробочных решений. Подобные задачи отлично регулируются системами контроля за складом, которые заметно облегчают работу кладовщиков.

<h3><i>Медицина</i></h3>>

В указе президента "О развитии искусственного интеллекта в Российской Федерации" № 490 от 10.10.2019 г. есть отдельное положение о повышении качества услуг здравоохранения за счет использования технологий ИИ. Потенциально внедрение искусственного интеллекта в медицине открывает большие возможности для контроля качества и автоматизации участков производственных процессов, которые достаточно типизированы и состоят из повторения рутинных операций. Чаще всего такими процессами являются скрининги и профилактические исследования, когда однотипная стандартизированная диагностика выполняется на больших объемах пациентов. Так как это условно здоровые люди, то при массовом анализе значительная часть исследований представляет собой норму и, как следствие, идеальный вариант для автоматизации.

Глобальные исследования подтверждают данную точку зрения. Согласно опросу Европейского общества рентгенорадиологии (European Society of Radiology), большинство врачей отдает предпочтение использованию ИИ для скрининга онкологических и сердечно-сосудистых заболеваний.

Что касается разделения ответственности врача и искусственного интеллекта, то к этому вопросу медицинские работники относятся скептически. Многие из них считают, что само по себе заключение без валидации врачом пациент вряд ли может воспринять и будет не действительным.

Мы сталкивались с известными ситуациями, когда алгоритм учили на компьютерных томограммах буквально находить белое на черном и в итоге он не понимал разницу между очагом в легком и содержимым кишечника (см рис ниже).

![Медицинский снимок](https://raw.githubusercontent.com/kzvyagin/introduction_to_cv_and_ml/main/chapter1/images/3.png)

В медицине мы имеем также дело с автоматизацией рутинных процессов, которые не требуют внимания доктора, но требуют сортировки пациентов. Кроме того, машинное обучение и анализ изображений активно применяются для автоматизации ручной разметки.
Некторые из применений:



<b>Предсказание падения артериального давления с помощью ИИ</b>

В 2018 году были опубликованы результаты исследований нескольких ученых, разработавших алгоритм прогнозирования аномального падения давления или гипотонии в процессе хирургического вмешательства.
Алгоритм разработан с помощью технологий машинного обучения в медицине. Исследователи использовали ИИ, который проанализировал данные более 1300 пациентов, у которых во время операции фиксировалось артериальное давление. Общая продолжительность наблюдения составила почти 546 тысяч минут. С помощью этих данных искусственный интеллект помог подготовить алгоритм прогнозирования гипотонии.
Алгоритм повторно проверяли на втором наборе данных других 204 пациентов. ИИ сумел правильно предсказать внезапное падение артериального давления в 84% случаев за 15 минут до падения, в 84% случаев – за 10 минут, и в 87% случаев – за 5 минут.
Исследователи считают, что алгоритм можно использовать во время операций, чтобы снизить вероятность возникновения осложнений.

<b>Распознавание рака кожи</b>

Искусственный интеллект в здравоохранении показывает впечатляющие результаты и в решении задачи раннего распознавания рака кожи. Эксперимент провели в 2018 году ученые из США, Франции и Германии, которые обучили нейросети идентифицировать изображения для диагностики онкозаболеваний кожных покровов. Машине предоставили более 100 тысяч снимков безвредных родинок и опасных для жизни меланом, а позднее показали эти же фотографии профессиональным дерматологам, которые попытались выявить рак по снимкам.
Машина справилась с задачей лучше специалистов. Она правильно распознала злокачественные образования в 95% случаев, тогда как люди показали результат только в 86%.

<b>ИИ в УЗИ-обследовании беременных</b>

Уже сегодня в некоторых британских больницах применяют новый способ тестирования плода на патологии, которые сложно или невозможно выявить другими средствами. Система работает на основе искусственного интеллекта, и в нее заложено более 350 тысяч снимков плодов с теми или иными отклонениями.

Система называется ScanNav и она способна давать врачу много полезной информации о патологиях плода, опираясь на имеющиеся в базе данные по другим пациенткам.

Пока ScanNav работает в тестовом режиме и используется только в акушерстве, но в будущем она может получить намного более широкое распространение и будет особенно полезна для стран, испытывающих острый дефицит во врачах.


<h2>Машинное обучение</h2>

Машинное обучение само по себе представляет самостоятельную дисциплину, которую можно изучать гораздо дольше и шире, чем рассчитан наш курс. Мы затронем основные аспекты работы с цифровыми изображениями и базовые техники машинного обучения, применимые как к обработке изложений, так и к другим самостоятельным областям их использования, без привязки к тематике обработки изображений. На теме обработки изображений эффективно можно показать техники машинного обучения. Во-первых, исходные данные для МО у нас практически везде, достаточно включить камеру смартфона и сделав серию кадром, получаем набор данных пригодный для машинного обучения. Во-вторых, одна из наиболее широко распространённых сфер применения МО это именно цифровая обработка изображений, улучшение фотографий, анализ изображений, преобразование изображений в текст, распознавание объектов, и прочее. В-третьих, цифровая обработка изображений позволяет подготовить данные для МО, а именно, корректно выбрать размер изображения или сегментировать его, скорректировать яркость и контрастность, убрать шум с изображения, найти контуры на изображении, определить преобладание того или иного цвета, и прочее. 

<b>Принадлежность машинного обучения к искусственному интеллекту</b>

![Медицинский снимок](https://raw.githubusercontent.com/kzvyagin/introduction_to_cv_and_ml/main/chapter1/images/4.png)

<h3>Типовая ML- команда</h3>

Во многом похожа на обычную IT команду. Рассмотрим отличия:

1) Аналитик данных (ML-expert, не программист на python, может применять любой фреймворк, и не статистик, и не математик, результат работы аналитика обученная ML модель
2) Инженер данных ( devpos + архитектор + программист разрабатывает pipeline ML проекта )
3) Менеджер ML – проекта, его задача добиться результата за понятное время управляя командой и ресурсами

<h4>Задачи инженера данных.</h4>
Во-первых, инженер данных проектирует архитектуру: он определяет, какое железо, софт и потоки данных требуются для выполнения проекта. Он выбирает и запускает железо: диски, вычислительные мощности и память. Он выбирает и устанавливает базы данных и софт. Он создает процессы обработки данных: данные нужно загружать, проверять, очищать, преобразовывать. В общем, готовить к работе аналитика. Также он должен запускать код, написанный аналитиком данных. И он должен коммуницировать с аналитиком данных и другими членами команды. Каковы выдвигаются требования к инженеру по данным? В идеале он должен знать и иметь навыки всего вышеперечисленного. Кроме этого, он умеет формулировать задачу и находить решение самостоятельно. Он умеет формулировать вопросы для того, чтобы правильно спроектировать архитектуру. Он имеет базовые знания в машинном обучении. Он умеет работать под давлением. У него развиты такие «мягкие» навыки, как эмпатия и коммуникации. И он умеет простыми словами объяснять сложные технологии. Бэкграунд инженера данных ─ это может быть и ETL-инженер, DevOps или программист.

<h4>Задачи аналитика данных.</h4>
Аналитик данных вместе с менеджером проекта и заказчиком ставят цели проекта. Проектирует и проводит эксперименты. Осуществляет статистический анализ данных. Ищет закономерности. Результаты работы визуализируются в виде презентаций, графиков и демо-приложений. Также он рассказывает о результатах команде. Он должен уметь создавать Roadmap по улучшению модели и автоматизировать регулярно повторяющиеся операции по анализу. И в целом по компании аналитик данных способствует культуре принятия решений на основе данных. Каковы же требования к аналитику данных? Это человек, который получил образование в области статистики, математики, физики и IT. Он прошел профильный курс или получил образование по машинному обучению. Он знает SQL. Он знает Python, который стал уже практически стандартом в этой области. Он обладает мягкими навыками. Он легко манипулирует массивами данных. Он понимает, как устроено железо и софт, на котором всё крутится. В идеале, он владеет технологиями больших данных, к примеру, Hadoop.

<h4>Задачи менеджера ML проекта.</h4>
Что же он делает, каковы его задачи? Он создает команду. Он ставит цели. Приоритезирует задачи. Взаимодействует с заказчиком и другими командами. И отчитывается по результатам. Каковы требования к менеджеру? Это человек, который должен знать машинное обучение, софт и железо. Он должен знать роли в проекте. Он должен понимать, что достижимо, а что ─ нет. Он имеет сильные коммуникативные навыки. Это помогающий тип, эмоционально устойчивый, вежливый и в то же время настойчивый. Бэкграунд менеджера проекта. Обычно это либо аналитик данных, который растет до менеджера, либо инженер данных, который вырастает до менеджера, либо это менеджер IT проекта, который прошел обучение по машинному обучению. Итак, сегодня мы поговорили о задачах и требованиях к аналитику данных, инженеру данных и менеджеру проекта по машинному обучению. 


<h3>Итак, рассмотрим поподробнее, что же такое МО?</h3>
 Вспомните, как вы учились писать — наверняка у вас были прописи с примерами правильного письма. А умножение? Вначале вы учили таблицу умножения с примерами, но, усвоив закономерности, вы уже сами начинали умножать более сложные числа. Вначале вы делали ошибки, но раз за разом ошибок становилось все меньше, потому что вы обучались. Машинное обучение построено по такому же принципу. С одной стороны есть набор <b>входных параметров</b> объекта (или <b>фичи</b>, англ: <b>features</b>), с другой стороны есть <b>набор решений</b> (<b>таргеты</b>, англ: <b>targets</b>), и есть какая-то <b>функция</b> (<b>модель</b>, англ: <b>model</b>), которая связывает эти фичи с этими решениями. Английские транскрипции используются по причине новизны области МО и большого количества вариантов переводов английских терминов. При этом возникает путаница при чтении зарубежной литературы. Самое правильное использовать однозначную транскрипцию без перевода, для четкой ассоциации знаний на русском языке и английском.

 Существует некоторая зависимость между ответами и объектами, но она неизвестна. Известна только конечная совокупность <b>прецедентов</b>— пар <b>объект - ответ</b>, называемая <b>обучающей выборкой</b>. На основе этих данных требуется восстановить неявную зависимость, а именно функцию отображения одного набора данных в набор ответов.

 Функция эта неизвестна но, тем не менее, можно построить такой алгоритм, который сможет связать входные параметры фичи с решениями.


 Как работает на практике машинное обучение? Представьте себе, что вы работаете в банке и вам нужно решить задачу — выдавать ли кредит клиенту? При этом у вас уже есть набор данных о том, какие клиенты брали кредиты, возвращали они их или нет. Поэтому вы можете создать алгоритм, который по набору данных конкретного клиента (таких как: сумма кредита, срок, его доход, пол, возраст и так далее) определит, вернет ли этот клиент кредит или не вернет, с той или иной степенью вероятности. Конечно же, это очень упрощенный пример, на самом деле все намного сложнее: и признаков у клиентов больше, и классов, к которым они относятся, тоже достаточно много. Пример, который я сейчас привел — это <b>обучение с учителем</b>, когда у вас есть наличие обучающих примеров. Бывает же обучение и <b>без учителя</b>, когда таких обучающих примеров нет, но есть некоторое предположение о том, как фичи связаны с таргетами. То есть предположения о некоторой целевой функции. Такие типы задач связаны с кластеризацией, например определения границ на изображениях,  распознавание объектов на изображениях, кошка или собака и с поиском правил ассоциаций. Еще пример из анализа фото и видео изображений. Например, какой бренд рекламируется на том или ином фото, и нам нужно посчитать какой бренд рекламируется сколько раз. Другой пример, вы смотрите на экран, и смотрите, нет ли каких-то проблем на производстве, с помощью машинных алгоритмов.

  Есть задачи <b>кластеризации</b> — когда нужно найти новые классы. Например, текстовые задачи — определить тематику обращений в службу поддержки, или принадлежность силуэта человека к определённому типу людей.  

  Собственно, почему машинное обучение стало так популярно? Во многом это связано именно с ростом и накоплением огромного количества данных. В особенности рост пошел в части не интерпретируемых моделей, когда вы можете получить результат, но объяснить, почему он так получился, вы не можете, тем не менее, это работает. И такие задачи есть с переводом голоса в текст — так называемые Speech-to-Text. Но есть и задачи, для которых очень важно понимать, почему принято было то или иное решение. Например, при постановке диагноза или в системе поддержки судьи, когда каждое решение — это решение о жизни и смерти того или иного человека. Соответственно, задачи можно разделить на <b>интерпретируемые</b> и <b>неинтерпретируемые</b>. И последний момент: почему так много алгоритмов машинного обучения уже придумано, и почему все время появляются новые и новые алгоритмы? Почему нельзя создать единственный алгоритм, который бы был универсальным и решал все классы задач? На этот вопрос отвечает теорема "no free lunch". <i>Она говорит о том, что в среднем, по всем возможным выборкам, все алгоритмы одинаковы.</i> То есть если вы возьмете какой-то алгоритм, который хорошо решает одну задачу, и начнете его применять ко всем другим задачам, то в среднем его точность будет не лучше всех остальных алгоритмов. Именно поэтому очень важно в проектах с машинным обучением уделять внимание составляющей, связанной с созданием модели, с научной составляющей. Также следует учитывать центральную предельную теорему, которая обозначает общее название ряда предельных теорем теории вероятностей, в которых устанавливается, что при большом числе слагаемых распределения сумм независимых случайных величин близки к нормальному распределению.

  Далее познакомимся с одним из межотраслевых стандартом анализа данных — методологией CRISP-DM. Это циклический процесс, описывающий общие подходы к аналитике данных, используемые в крупных или промышленных проектах независимо от конкретной задачи и индустрии. Обычно может быть представлен в виде диаграммы, и вы можете легко ее найти в Интернете, для того чтобы  ознакомиться с эти подходом.

  ![CRISP DM](https://raw.githubusercontent.com/kzvyagin/introduction_to_cv_and_ml/main/chapter1/images/5.png)


  Это изображение диаграммы CRISP-DM (от английского Cross-Industry Standard Process for Data Mining) — межотраслевой стандартный процесс исследования данных. Это проверенная в промышленности и наиболее распространённая методология, первая версия которой была представлена в Брюсселе в марте 1999 года, а пошаговая инструкция опубликована в 2000 году.

  CRISP-DM описывает жизненный цикл исследования данных и прекрасно подходит под задачи машинное обучение. Этот цикл состоит из 6 фаз, от постановки задачи с точки зрения заказчика до внедрения технического решения.

  На данный момент самый трудоемкий, до 80-90 % времени от проекта и самый важный это подготовка данных. В 21 –м веке данные приобрели статус новой нефти. Без хорошего датасета изображений не натренировать конкурентно способную модель, без качественно набора данных покупок покупателей не построить модель для предсказания спроса или не найти скрытую зависимость, повышающую объем продаж на 1%, что в рамках Х5 групп влечет миллионные прибыли. По данным издания forbes.ru, на мероприятие «Data Fusion — 2022 ВТБ» в 2022  заместитель руководителя технологического блока, старший вице-президент ВТБ Сергей Безбогов  утверждает «Данные можно сравнить с нефтью, водой и даже кровью, ежедневно необходимыми для работы бизнеса.  А технологичность Data Science и аналитики данных растет экспоненциальными темпами год от года», по данным статьи «Новая нефть: почему бизнесу необходимы данные и что такое Data Fusion» от 20 ого апреля 2022 г.

  Знать машинное обучение мало, нужно понимать, как встроить машинное обучение в бизнес-процессы, и самое главное понять, какой это дает эффект, какую проблему для бизнеса решает машинное обучение. Поэтому первым этапом в этом стандарте стоит понимание бизнеса, а именно решаемой задачи. Следующий этап — это анализ данных. Сбор данных, описание данных, изучение данных — все это очень важно, потому что данные в компании, как правило, хранятся в разных местах, разных форматах, и есть данные более доступные, есть менее доступные. Есть данные, которые легко анализировать. Есть данные, которые анализировать сложно. Все это нужно внимательно изучить и посмотреть. В реальных проектах данные обычно грязные. То есть эти данные нужно очищать и подготавливать и это занимает до 80 % времени. В нашем случае, данные — это изображения, поэтому необходимо уметь подготавливать данные корректным образом для МО, собственно чему и посвящен наш курс. Далее переходим к следующему этапу, а именно моделированию. Моделирование — это процесс создания модели машинного обучения. Важно понять объект, с которым вы работаете, и также понять признаки, которыми обладает этот объект, так называемый feature engineering — то есть выбор важных признаков, а также выбор перечня моделей, которые вы будете использовать, потому что не все модели могут оказаться такими хорошими, как кажутся вначале. А для этого нужно понимать, как вы будете оценивать качество этих моделей. Дальше вы обучаете модели и тестируете модели. Соответственно, само по себе моделирование тоже является итерационным процессом, в котором надо все время возвращаться и смотреть, все ли признаки вы учли, может быть, есть избыточные признаки, какие модели работают лучше, а какие хуже. После того как вы завершили с машинным обучением, вы проверяете оценку решения, на то, насколько вы смогли добиться каких-то результатов, какой у вас есть прогресс. И тогда уже можно понимать, какие следующие шаги вы будете совершать. И только после того, как понятно, что все это приносит ощутимый эффект для бизнеса, можно готовить внедрение. Само по себе внедрение является отдельным большим проектом который мы тут не рассматриваем. 

  Для того, чтобы сделать весь процесс менее затратным и более эффективным, делается Proof-of-Concept, то есть составляется гипотеза. Proof-of-Concept — это такой небольшой предпроект, в рамках которого вы понимаете, что вообще машинное обучение способно решить вашу задачу и оно дает ощутимый эффект. 

  Последовательность между фазами определена не строго, переходы могут повторяться от итерации к итерации. Все фазы CRISP-DM делятся на задачи, по итогам каждой должен быть достигнут конкретный результат.

  Рассмотрим подробнее фазы жизненного цикла исследования данных по CRISP-DM:

  <ol><li><b>Понимание бизнеса (Business Understanding)</b> – определение целей проекта и требований со стороны бизнеса. Затем эти знания конвертируются в постановку задачи интеллектуального анализа данных и предварительный план достижения целей проекта. 
  
  Задачи фазы Business Understanding:
  <ol><li> Определить бизнес-цели</li>
    <li>Оценить ситуацию</li>
    <li>Определить цели анализа данных</li>
    <li>Составить план проекта</li></ol>
  </li>

  <li><b>Начальное изучение данных (Data Understanding)</b> – сбор данных и знакомство с информацией, выявление проблем с качеством данных (ошибки или пропуски). Необходимо понять, какие сведения имеются, попробовать отыскать интересные наборы данных или сформировать гипотезы о наличии в них скрытых закономерностей. 
  
  Задачи фазы Data Understanding:  
  <ol><li> Собрать исходные данные</li>
    <li>Описать данные</li>
    <li>Исследовать данные</li>
    <li>Проверить качество данных</li></ol>
  </li>
</li>
  <li>
  <b>Подготовка данных (Data Preparation)</b> – получение итогового набора данных, которые будут использоваться при моделировании, из исходных разнородных и разноформатных данных. 
  
  Задачи фазы Data Preparation:
    <ol><li>Отобрать данные (таблицы, записи и атрибуты)</li>
    <li>Очистить данные, в т.ч. выполнить их конвертацию и подготовку к моделированию</li>
    <li>Сделать производные данные (бутсрэппинг)</li>
    <li>Объединить данные</li>
    <li>Привести данные в нужный формат</li>
    </ol>
   <b>Бутсрэппинг</b> -метод определения статистик вероятностных распределений, основанный на многократной генерации псевдовыборок методом Монте-Карло на основе имеющейся выборки.
  </li>
  <li><b>Моделирование (Modeling)</b> – в этой фазе к данным применяются разнообразные методики моделирования, строятся модели и их параметры настраиваются на оптимальные значения. Обычно для решения любой задачи анализа данных существует несколько различных подходов. Некоторые подходы накладывают особые требования на представление данных. Таким образом часто бывает нужен возврат на шаг назад к фазе подготовки данных. 
  
  Задачи фазы Modeling:
  <ol><li> Выбрать методику моделирования</li>
    <li>Сделать тесты для модели</li>
    <li>Построить модель</li>
    <li>Оценить модель</li></ol>
  </li>
  <li><b>Оценка (Evaluation)</b> – анализ количественных характеристик качества модели, подтверждение или опровержение того, что, благодаря построенной модели все бизнес-цели достигнуты. Основной целью этапа является поиск важных бизнес-задач, которым не было уделено должного внимания. 
  
  Задачи фазы Evaluation:
   <ol><li>Оценить результаты</li>
    <li>Сделать тесты для модели</li>
    <li>Сделать ревью процесса</li>
    <li>Определить дальнейшие шаги</li></ol>

  </li>
  <li>Внедрение (Deployment) – в зависимости от требований фаза развертывания может быть простой (составление финального отчета) или сложной, например, автоматизация процесса анализа данных для решения бизнес-задач. Обычно развертывание — это внедрение полученных моделей в прикладную сферу. 
  
  Задачи фазы Deployment:
  
   <ol><li>Запланировать развертывание</li>
    <li>Запланировать поддержку и мониторинг развернутого решения</li>
    <li>Сделать финальный отчет</li>
    <li>Сделать ревью проекта</li></ol>

</li>
  </ol>

  Вернемся к нашей теме. Поскольку уже существуют стандарт для проекта связанного с МО и обработкой изображений, вы спросите, может Терминатор уже рядом? Отвечая на такой вопрос, осветим два понятия:

  <b>Так что мы создаем, что машина сможет сделать</b>
- Запоминать
- Выполнять программу
- Воспроизводить
- Предсказывать
- Выбирать лучшее

<b>Машина не может </b>
- Самостоятельно резко поумнеть
- Выйти за рамки задачи или набора данных для обучения
- Убить всех людей

<h3>Рассмотри подробно виды машинного обучения:</h3>

Наиболее распространены следующие типы задач — это задачи классификации, задачи кластеризации, задачи регрессии для прогнозирования. И немного поговорим об ансамблях моделей. 

<h4>Задача классификации.</h4>
<b>Задача классификации</b> состоит в том, что у вас есть какой-то известный набор объектов, уже разделенный на классы, и это есть ваша обучающая выборка. Требуется построить такой алгоритм, который способен классифицировать произвольный объект из вашего множества, то есть сопоставить его с известным уже классом. По сути, это обучение с учителем. Например, задача классификации — это распознавание индексов на конвертах, или более общая задача — распознавание символов (скажем, при сканировании книг или каких-то напечатанных или же рукописных текстов). Задачи классификации имеют огромное применение, но давайте посмотрим чуть подробнее, как они работают. Посмотрим на такой способ классификации, как дерево решений. 

<b>Дерево решений</b> состоит из узлов и состоит из листьев. Листья находятся в конце дерева решений, а узлы содержат в себе классификационные правила. Эти правила позволяют вам определять те или иные характеристики. Скажем, вы хотите определить кредитный рейтинг — высокий или низкий. И если возраст вашего заемщика от 30 до 40 лет, а доход высокий, то вы говорите, что кредитный рейтинг у него высокий. Если же у него возраст от 30 до 40, но доход не высокий, то кредитный рейтинг будет низким. И такая иерархия правил позволяет вам определять классы объектов и, соответственно, использовать это для вашего бизнеса. Другой способ классификации — использовать нейронную сеть. 

<b>Нейронные сети</b> представляют собой модели, имитирующие принципы работы головного мозга. Следует отметить, что это лишь математическая модель, биологическая нейронная сеть устроена иначе. А если говорить подробнее, то нейронная сеть состоит из простейших вычислительных элементов — это искусственные нейроны, и они связаны друг с другом. Каждый нейрон имеет несколько входных и одну выходную связь. Входные же связи имеют вес, на который умножается сигнал, который через нее приходит. Например, посмотрим на нейронную сеть, состоящую из нескольких слоев. Выделяют: входной слой — это первый слой, на который приходит сигнал; есть выходной слой — из которого выходят уже ответы; и все, что между ними — это скрытые слои. И если сеть этих нейронов содержит очень-очень много слоев, то говорят о том, что это глубокое машинное обучение (или так называемый Deep Learning).  

<h4>Задача кластеризации</h4>

Другая задача — это  <b>задача кластеризации</b>. Это задача разбиения множества объектов на группы, которые мы называем кластерами. Внутри каждой группы должны оказаться связанные, похожие друг на друга объекты, и объекты разных групп должны как можно сильнее отличаться друг от друга. Главное отличие кластеризации от классификации состоит в том, что перечень групп четко не задан, а определяется в процессе работы алгоритма, и, по сути, это обучение без учителя. Задача кластеризации используется для разных целей. Например, для построения гипотез, чтобы понять, насколько информативны свойства объектов — это может облегчить анализ данных, когда каждому кластеру проводится отдельный анализ. То есть вы разбили на много кластеров, и для каждого кластера используете какие-то свои (для этого кластера) методы. Можно также сжимать данные. Делается это очень просто — оставляем по одному представителю от каждого кластера, и у нас сразу же данных становится меньше, а вся выборка, тем не менее, представлена. И, конечно же, задача обнаружения аномалий — когда кластеры с малым числом объектов каким-то образом характеризуют какие-то процессы, которые могут оказаться нежелательными. Например, какие-то мошеннические действия могут выделиться в отдельный кластер, и вы увидите, что там какие-то есть, на уровне бизнеса, связанные вещи. Скажем, там встречаются одни и те же фамилии, одни и те же подписанты документов и так далее. Это может вам очень быстро помочь найти тех или иных нарушителей. Допустим, у нас есть магазин — розничная сеть, в которую приходит очень-очень много клиентов, и мы хотим понять, каким клиентам какие продукты продавать. Мы используем для этого как раз кластеризацию. То есть мы разбиваем нашу клиентскую базу на кластеры, и потом смотрим, к какому кластеру какие предложения лучше подходят. 


<h4>Задача регрессии</h4>

Другая задача — это <b>задача регрессии</b>. Собственно, нужно предсказать какое-то число в нашей задаче. Например, задача прогнозирования продаж. Посмотрим на имеющиеся данные: если представить, что зависимость между этими данными линейная, то вполне можно провести прямую линию через облако точек, и тогда нужное нам решение будет на этой прямой, а, собственно, параметр этой прямой — это есть угол наклона. Меняя угол наклона, мы будем смотреть, насколько хорошо и точно работает эта модель. Конечно, это самый простой способ, самая простая линейная регрессия, но также могут быть и другие использованы функции для того, чтобы представить себе ту зависимость, которая есть между точками. 

<b>Ансамбли моделей</b> это способ работы машинного обучения — это делать. 


<b>Бустинг</b> - самый известный (от английского "boosting" — улучшение). Это процедура последовательного построения композиции алгоритмов машинного обучения, когда каждый следующий алгоритм стремится компенсировать недостатки композиции всех предыдущих алгоритмов. И в последние годы бустинг остается одним из наиболее популярных методов машинного обучения. Причины простые — это простота использования, универсальность и гибкость, потому что можно строить различные модификации, так как вы легко меняете модели, и главное — высокая обобщающая способность. 

<b>Бэггинг</b> - это технология классификации, которая, в отличие от бустинга, строит все элементарные классификаторы работающими независимо, то есть они работают параллельно. И идея заключается в том, что классификаторы не исправляют ошибки друг друга, а компенсируют их при голосовании. Эти способы, собственно, позволяют сильно улучшить качество модели.

<h2>Примеры</h2>

Например известный сервис Ностальгия, который позволяет сделать анимацию фотографий. Человек загружает свое фото на сайт, и сервис анимирует изображение при помощи нейросетей. А именно добавляет движение глаз, легкие повороты головы и минимальную мимику. 

Следующий известный пример применения МО для изображений — это колоризация изображений. 

Распознавание лиц в видеопотоке, и определение автомобильных номеров.
Увеличение разрешения изображения.

Удаление сетки рыбицы и прочих заслоняющих объектов из фото.

Еще пример, Московская система видеонаблюдения и контроля соблюдения ПДД, а именно выезд на встречную полосу, пересечение двойной сплошной и прочие.