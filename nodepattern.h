#ifndef NODEPATTERN_H
#define NODEPATTERN_H

/*!
 * Класс, список шаблонов для определенного узла
 */
class nodePattern
{
public:
    nodePattern();

	QString * default; //!< стандартный шаблон;
	QList<variant *> variants; //!< список альтернативных шаблонов.
};

#endif // NODEPATTERN_H
