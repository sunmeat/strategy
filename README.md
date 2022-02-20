# strategy pattern cpp example
![](https://refactoring.guru/images/patterns/content/strategy/strategy.png)

Стратегия — это поведенческий паттерн проектирования, который определяет семейство схожих алгоритмов и помещает каждый из них в собственный класс, после чего алгоритмы можно взаимозаменять прямо во время исполнения программы.

In computer programming, the strategy pattern (also known as the policy pattern) is a behavioral software design pattern that enables selecting an algorithm at runtime.
Instead of implementing a single algorithm directly, code receives run-time instructions as to which in a family of algorithms to use.

Strategy lets the algorithm vary independently from clients that use it. Strategy is one of the patterns included in the influential book Design Patterns by Gamma et al
that popularized the concept of using design patterns to describe how to design flexible and reusable object-oriented software.
Deferring the decision about which algorithm to use until runtime allows the calling code to be more flexible and reusable.

For instance, a class that performs validation on incoming data may use the strategy pattern to select a validation algorithm depending on the type of data,
the source of the data, user choice, or other discriminating factors. These factors are not known until run-time and may require radically different validation to be performed.
The validation algorithms (strategies), encapsulated separately from the validating object, may be used by other validating objects in different areas of the system
(or even different systems) without code duplication.

Typically, the strategy pattern stores a reference to some code in a data structure and retrieves it. This can be achieved by mechanisms such as the native function pointer,
the first-class function, classes or class instances in object-oriented programming languages, or accessing the language implementation's internal storage of code via reflection.
