//
// Created by krutna on 08.11.18.
//

#pragma once

class func5 : public function {
    std::string functionText;
public:
    func5();
    std::string getText();
    double execute(double x);
};