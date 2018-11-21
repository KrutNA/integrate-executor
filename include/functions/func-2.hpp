//
// Created by krutna on 08.11.18.
//

#pragma once

class func2 : public function {
    std::string functionText;
public:
    func2();
    std::string getText();
    double execute(double x);
};