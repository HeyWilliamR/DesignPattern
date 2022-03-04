# 装饰器模式

装饰器可以动态的给一个对象添加一些额外的职责，就增加功能来说，装饰器模式比生成子类更加灵活。

![decorator](..\pictures\decorator.png)

Component定义一个对象接口，可以给这些对象动态的添加一些职责。ConcreteComponent是定义了一个具体的对象，也可以给这个对象添加一些职责，有时二者可以为同一个类。Decorator伪装是抽象类，继承了Component，从外类来扩展Component类的功能，但是对于Component来说，无需知道Decorator的存在。至于ConcreteDecorator就是具体的修饰对象，起到给Component添加一些额外的装饰功能。

这样每个装饰类和实体类相分离，装饰类只关心自己的功能，不需要关心如何被添加到对象中去。

## 装饰模式的适用场景

 如果你希望在无需修改代码的情况下即可使用对象， 且希望在运行时为对象新增额外的行为， 可以使用装饰模式。

 装饰能将业务逻辑组织为层次结构， 你可为各层创建一个装饰， 在运行时将各种不同逻辑组合成对象。 由于这些对象都遵循通用接口， 客户端代码能以相同的方式使用这些对象。

 如果用继承来扩展对象行为的方案难以实现或者根本不可行， 你可以使用该模式。

 许多编程语言使用 `final`最终关键字来限制对某个类的进一步扩展。 复用最终类已有行为的唯一方法是使用装饰模式： 用封装器对其进行封装。

## 装饰模式优缺点

| 优点                                                         | 缺点                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1.无需创建子类来扩展对象行为<br />2.可以在运行时动态添加或删除对象功能<br />3.可以用多个装饰封装对象来组合几种行为。<br />4. *单一职责原则*。 你可以将实现了许多不同行为的一个大类拆分为多个较小的类。 | 1. 在封装器栈中删除特定封装器比较困难。<br />2.实现行为不受装饰栈顺序影响的装饰比较困难。<br />3.各层的初始化配置代码看上去可能会很糟糕。 |

## 与其他模式的关系

- [适配器模式](https://refactoringguru.cn/design-patterns/adapter)可以对已有对象的接口进行修改， [装饰模式](https://refactoringguru.cn/design-patterns/decorator)则能在不改变对象接口的前提下强化对象功能。 此外， *装饰*还支持递归组合， *适配器*则无法实现。

- [适配器](https://refactoringguru.cn/design-patterns/adapter)能为被封装对象提供不同的接口， [代理模式](https://refactoringguru.cn/design-patterns/proxy)能为对象提供相同的接口， [装饰](https://refactoringguru.cn/design-patterns/decorator)则能为对象提供加强的接口。

- [责任链模式](https://refactoringguru.cn/design-patterns/chain-of-responsibility)和[装饰模式](https://refactoringguru.cn/design-patterns/decorator)的类结构非常相似。 两者都依赖递归组合将需要执行的操作传递给一系列对象。 但是， 两者有几点重要的不同之处。

  [责任链](https://refactoringguru.cn/design-patterns/chain-of-responsibility)的管理者可以相互独立地执行一切操作， 还可以随时停止传递请求。 另一方面， 各种*装饰*可以在遵循基本接口的情况下扩展对象的行为。 此外， 装饰无法中断请求的传递。

- [组合模式](https://refactoringguru.cn/design-patterns/composite)和[装饰](https://refactoringguru.cn/design-patterns/decorator)的结构图很相似， 因为两者都依赖递归组合来组织无限数量的对象。

  *装饰*类似于*组合*， 但其只有一个子组件。 此外还有一个明显不同： *装饰*为被封装对象添加了额外的职责， *组合*仅对其子节点的结果进行了 “求和”。

  但是， 模式也可以相互合作： 你可以使用*装饰*来扩展*组合*树中特定对象的行为。

- 大量使用[组合](https://refactoringguru.cn/design-patterns/composite)和[装饰](https://refactoringguru.cn/design-patterns/decorator)的设计通常可从对于[原型模式](https://refactoringguru.cn/design-patterns/prototype)的使用中获益。 你可以通过该模式来复制复杂结构， 而非从零开始重新构造。

- [装饰](https://refactoringguru.cn/design-patterns/decorator)可让你更改对象的外表， [策略模式](https://refactoringguru.cn/design-patterns/strategy)则让你能够改变其本质。

- [装饰](https://refactoringguru.cn/design-patterns/decorator)和[代理](https://refactoringguru.cn/design-patterns/proxy)有着相似的结构， 但是其意图却非常不同。 这两个模式的构建都基于组合原则， 也就是说一个对象应该将部分工作委派给另一个对象。 两者之间的不同之处在于*代理*通常自行管理其服务对象的生命周期， 而*装饰*的生成则总是由客户端进行控制。