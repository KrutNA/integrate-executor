//
// Created by krutna on 08.11.18.
//

#pragma once

class func1 : public function {
    std::string functionText;
public:
    func1();
    std::string getText();
    double execute(double x);
};
