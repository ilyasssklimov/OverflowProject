#pragma once

#include <iostream>

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WBootstrapTheme.h>
#include <Wt/WTheme.h>

#include <Wt/WVBoxLayout.h>
#include <Wt/WLabel.h>

#include <Wt/WInteractWidget.h>

class Object {
public:
    Object() {};
    virtual std::string info() {return "";};
};

template <typename T>
class ObjectWidget : public Wt::WContainerWidget
{
static_assert(std::is_base_of<Object, T>::value, "Ошибка наследования.");
public:
    ObjectWidget(T obj) {
        setContentAlignment(Wt::AlignmentFlag::Center);
        //decorationStyle().setBackgroundColor(Wt::WColor(226, 226, 226));
        auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());
        addStyleClass("row rounded-3 bg-secondary");
        info_ = layout->addWidget(std::make_unique<Wt::WText>(obj.info()));
    }
public:
    Wt::WPushButton  *show_; // кнопка - показать объект
private:
    Wt::WText        *info_; // вся информация об объекте
};

