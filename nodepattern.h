#ifndef NODEPATTERN_H
#define NODEPATTERN_H
#include "variant.h"

/*!
 * \brief список шаблонов для определенного узла.
 * Класс, список шаблонов для определенного узла. defaultPattern - стандартный шаблон. variantPatterns - массив альтернативных шаблонов
 */
class nodePattern
{
public:
    nodePattern();
	nodePattern(const nodePattern &);

	QString * defaultPattern; //!< стандартный шаблон;
	QList<variant *> variantPatterns; //!< список альтернативных шаблонов.
};

#endif // NODEPATTERN_H
