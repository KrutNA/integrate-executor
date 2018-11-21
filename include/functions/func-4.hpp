//
// Created by krutna on 08.11.18.
//

#pragma once

class func4 : public function {
    std::string functionText;
public:
    func4();
    std::string getText();
    double execute(double x);
};