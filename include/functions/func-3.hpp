//
// Created by krutna on 08.11.18.
//

#pragma once

class func3 : public function {
    std::string functionText;
public:
    func3();
    std::string getText();
    double execute(double x);
};