#ifndef PATTERNCONTAINER_H
#define PATTERNCONTAINER_H
#include "variant.h"
#include "nodeType.h"
#include "nodepattern.h"
#include <QStringList>
#include <QMap>

const QMap<QString,nodeType> & buildTagsMap();

/*!
 * \brief Класс, содержащий список всех шаблонов
 * Класс, содержащий список всех шаблонов с возможность получения набора шаблонов для определенного тега
 */
class patternContainer
{
public:
	QStringList defaults; ///<список стандартных шаблонов, 
    QList<variant> allVariants; ///<список альтернативных шаблонов
	QMap<nodeType,nodePattern> nodePatterns;///<список шаблонов по тегам, ключ – тип узла, значение – список шаблонов.
	
	patternContainer();	///<конструктор по умолчанию

	/*!
	 * добавление стандартного шаблона в defaults и в соответствующую ячейку nodePatterns
	 * \param[in] tag	название тега
	 * \param[in] pattern	шаблон
	 */
	void addDefault(QString &tag, QString pattern);

	/*!
	 * добавление альтернативного варианта шаблона в allVariants и в соответствующую ячейку nodePatterns, согласно полю item.type.
	 * \param[in] item добавляемый шаблон
	 */
	void addVariant(variant item);

	/*!
	 *  возвращает список шаблонов для текущего узла
	 * \param[in] type требуемый тип узла
	 * \return ссылка на список шаблонов из контейнера nodePatterns
	 */
	nodePattern * getPatternFromType(nodeType type);
};

#endif // PATTERNCONTAINER_H
