#ifndef VARIANT_H
#define VARIANT_H
#include <QList>
#include <QString>

/*!
 * \brief  ласс, содержащий альтернативный вариант шаблона и условие его применени€
 *  ласс, содержащий альтернативный вариант шаблона и условие его применени€
 */
class variant
{
public:
	unsigned long long type;///<битовые флажки. «начение по умолчанию 0; 1 на i позиции Ц тип i допустим дл€ использовани€. ‘лажки задаютс€ с помощью emun nodeType
    unsigned long long parentType;///<аналогично \ref type дл€ типа родител€
	QList<unsigned long long> childiType;///<аналогично \ref type дл€ типа i-того ребенка
	unsigned long long childType;///<аналогично \ref type дл€ типа любого из потомков,
	QString content;///<регул€рное выражение  дл€ проверки текстового содержани€ узла, пуста€ строка по умолчанию
	QString parentContent;///<аналогично \ref content дл€ родител€
	QList<QString> childiContent;///<аналогично \ref content дл€ i - ребенка
	QString form;///<требуема€ форма, указанна€ после знака $ и цифры в шаблоне
	QString m;///<дл€ квантификаторов и ссылок
	QString n;///<дл€ квантификаторов
	QString pattern;///<текст шаблона

	variant();
};

#endif // VARIANT_H
