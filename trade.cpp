#include "trade.hpp"


trade::trade(/* args */)
{
	this->_period = 0;
	this->testing = 0;

	this->_BTC = 0;
	this->_ETH = 0;
	this->_USDT = 1000;

    this->_g_BTC_ETH = 0;
    this->_r_BTC_ETH = 0;
    this->_s_BTC_ETH = 0;
	this->_m_BTC_ETH = -1;

    this->_g_USDT_ETH = 0;
    this->_r_USDT_ETH = 0;
    this->_s_USDT_ETH = 0;
	this->_m_USDT_ETH = -1;

    this->_g_USDT_BTC = 0;
    this->_r_USDT_BTC = 0;
    this->_s_USDT_BTC = 0;
	this->_m_USDT_BTC = -1;
}

trade::~trade()
{

}

int trade::calcul_g_BTC_ETH()
{
	this->_period;
    double moyenne1, moyenne2, moyenne3, moyenne4, g_high, g_low = 0;
    if (this->_vector_BTC_ETH.size() > this->_period){
        for (int i = this->_vector_BTC_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            if (this->_vector_BTC_ETH[i].high > this->_vector_BTC_ETH[i - 1].high){
                moyenne1 += this->_vector_BTC_ETH[i].high;
                moyenne2 += this->_vector_BTC_ETH[i - 1].high;
            }
			if (this->_vector_BTC_ETH[i].low > this->_vector_BTC_ETH[i - 1].low){
                moyenne3 += this->_vector_BTC_ETH[i].low;
                moyenne4 += this->_vector_BTC_ETH[i - 1].low;
            }
        }
        g_high = (moyenne1 / this->_period) - (moyenne2 / this->_period);
		g_low = (moyenne3 / this->_period) - (moyenne4 / this->_period);
		this->_g_BTC_ETH = (g_high + g_low) / 2;
        if (this->_g_BTC_ETH < 0)
            this->_g_BTC_ETH = 0;
    }
	return this->_g_BTC_ETH;
}

int trade::calcul_r_BTC_ETH()
{
	this->_period;
    double v1, v2, r_high, r_low = 0;
    double temp_r = this->_r_BTC_ETH;

    if (this->_vector_BTC_ETH.size() > this->_period){
        v1 = this->_vector_BTC_ETH[this->_vector_BTC_ETH.size() - 1].high;
        v2 = this->_vector_BTC_ETH[this->_vector_BTC_ETH.size() - (1 + this->_period)].high;
        r_high = ((v1 * 100) / v2) - 100;

		v1 = this->_vector_BTC_ETH[this->_vector_BTC_ETH.size() - 1].low;
        v2 = this->_vector_BTC_ETH[this->_vector_BTC_ETH.size() - (1 + this->_period)].low;
        r_low  = ((v1 * 100) / v2) - 100;

		this->_r_BTC_ETH = (r_high + r_low) / 2;
    }
	return this->_r_BTC_ETH;
}

int trade::calcul_s_BTC_ETH()
{
	this->_period;
    double moyenne1, temp1, moyenne2, temp2, s_high, s_low;
    moyenne1, moyenne2, temp1, temp2 = 0;
    if (this->_vector_BTC_ETH.size() > this->_period - 1){

        for (int i = this->_vector_BTC_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            moyenne1 += this->_vector_BTC_ETH[i].high;
        }
        moyenne1 /= this->_period;
        for (int i = this->_vector_BTC_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            temp1 += pow(this->_vector_BTC_ETH[i].high - moyenne1, 2);
        }

		for (int i = this->_vector_BTC_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            moyenne2 += this->_vector_BTC_ETH[i].low;
        }
        moyenne2 /= this->_period;
        for (int i = this->_vector_BTC_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            temp2 += pow(this->_vector_BTC_ETH[i].low - moyenne2, 2);
        }

		s_high = sqrt(temp1 / this->_period);
		s_low = sqrt(temp2 / this->_period);
		this->_s_BTC_ETH = (s_high + s_low) / 2;
    }
	return this->_s_BTC_ETH;
}

int trade::calcul_moy_BTC_ETH()
{
	long double avg_high = 0, avg_low = 0, avg = 0;
	for (int i = 0; i < this->_vector_BTC_ETH.size(); i++){
		avg_high += this->_vector_BTC_ETH[i].close;
	}
	avg_high = avg_high / this->_vector_BTC_ETH.size();
	this->_m_BTC_ETH = avg_high;
	return avg;
}

int trade::calcul_g_USDT_BTC()
{
	this->_period;
    double moyenne1, moyenne2, moyenne3, moyenne4, g_high, g_low = 0;
    if (this->_vector_USDT_BTC.size() > this->_period){
        for (int i = this->_vector_USDT_BTC.size() - 1, j = 0; j < this->_period; i--, j++){
            if (this->_vector_USDT_BTC[i].high > this->_vector_USDT_BTC[i - 1].high){
                moyenne1 += this->_vector_USDT_BTC[i].high;
                moyenne2 += this->_vector_USDT_BTC[i - 1].high;
            }
			if (this->_vector_USDT_BTC[i].low > this->_vector_USDT_BTC[i - 1].low){
                moyenne3 += this->_vector_USDT_BTC[i].low;
                moyenne4 += this->_vector_USDT_BTC[i - 1].low;
            }
        }
        g_high = (moyenne1 / this->_period) - (moyenne2 / this->_period);
		g_low = (moyenne3 / this->_period) - (moyenne4 / this->_period);
		this->_g_USDT_BTC = (g_high + g_low) / 2;
        if (this->_g_USDT_BTC < 0)
            this->_g_USDT_BTC = 0;
    }
	return this->_g_USDT_BTC;
}

int trade::calcul_r_USDT_BTC()
{
	this->_period;
    double v1, v2, r_high, r_low = 0;
    double temp_r = this->_r_USDT_BTC;

    if (this->_vector_USDT_BTC.size() > this->_period){
        v1 = this->_vector_USDT_BTC[this->_vector_USDT_BTC.size() - 1].high;
        v2 = this->_vector_USDT_BTC[this->_vector_USDT_BTC.size() - (1 + this->_period)].high;
        r_high = ((v1 * 100) / v2) - 100;

		v1 = this->_vector_USDT_BTC[this->_vector_USDT_BTC.size() - 1].low;
        v2 = this->_vector_USDT_BTC[this->_vector_USDT_BTC.size() - (1 + this->_period)].low;
        r_low  = ((v1 * 100) / v2) - 100;

		this->_r_USDT_BTC = (r_high + r_low) / 2;
    }
	return this->_r_USDT_BTC;
}

int trade::calcul_s_USDT_BTC()
{
	this->_period;
    double moyenne1, temp1, moyenne2, temp2, s_high, s_low;
    moyenne1, moyenne2, temp1, temp2 = 0;
    if (this->_vector_USDT_BTC.size() > this->_period - 1){

        for (int i = this->_vector_USDT_BTC.size() - 1, j = 0; j < this->_period; i--, j++){
            moyenne1 += this->_vector_USDT_BTC[i].high;
        }
        moyenne1 /= this->_period;
        for (int i = this->_vector_USDT_BTC.size() - 1, j = 0; j < this->_period; i--, j++){
            temp1 += pow(this->_vector_USDT_BTC[i].high - moyenne1, 2);
        }

		for (int i = this->_vector_USDT_BTC.size() - 1, j = 0; j < this->_period; i--, j++){
            moyenne2 += this->_vector_USDT_BTC[i].low;
        }
        moyenne2 /= this->_period;
        for (int i = this->_vector_USDT_BTC.size() - 1, j = 0; j < this->_period; i--, j++){
            temp2 += pow(this->_vector_USDT_BTC[i].low - moyenne2, 2);
        }

		s_high = sqrt(temp1 / this->_period);
		s_low = sqrt(temp2 / this->_period);
		this->_s_USDT_BTC = (s_high + s_low) / 2;
    }
	return this->_s_USDT_BTC;
}

int trade::calcul_moy_USDT_BTC()
{
	double avg_high, avg_low, avg = 0;
	for (int i = 0; i < this->_vector_USDT_BTC.size(); i++){
		avg_high += this->_vector_USDT_BTC[i].close;
	}
	avg_high = avg_high / this->_vector_USDT_BTC.size();
	this->_m_USDT_BTC = avg_high;
	return avg;
}

int trade::calcul_g_USDT_ETH()
{
	this->_period;
    double moyenne1, moyenne2, moyenne3, moyenne4, g_high, g_low = 0;
    if (this->_vector_USDT_ETH.size() > this->_period){
        for (int i = this->_vector_USDT_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            if (this->_vector_USDT_ETH[i].high > this->_vector_USDT_ETH[i - 1].high){
                moyenne1 += this->_vector_USDT_ETH[i].high;
                moyenne2 += this->_vector_USDT_ETH[i - 1].high;
            }
			if (this->_vector_USDT_ETH[i].low > this->_vector_USDT_ETH[i - 1].low){
                moyenne3 += this->_vector_USDT_ETH[i].low;
                moyenne4 += this->_vector_USDT_ETH[i - 1].low;
            }
        }
        g_high = (moyenne1 / this->_period) - (moyenne2 / this->_period);
		g_low = (moyenne3 / this->_period) - (moyenne4 / this->_period);
		this->_g_USDT_ETH = (g_high + g_low) / 2;
        if (this->_g_USDT_ETH < 0)
            this->_g_USDT_ETH = 0;
    }
	return this->_g_USDT_ETH;
}

int trade::calcul_r_USDT_ETH()
{
	this->_period;
    double v1, v2, r_high, r_low = 0;
    double temp_r = this->_r_USDT_ETH;

    if (this->_vector_USDT_ETH.size() > this->_period){
        v1 = this->_vector_USDT_ETH[this->_vector_USDT_ETH.size() - 1].high;
        v2 = this->_vector_USDT_ETH[this->_vector_USDT_ETH.size() - (1 + this->_period)].high;
        r_high = ((v1 * 100) / v2) - 100;

		v1 = this->_vector_USDT_ETH[this->_vector_USDT_ETH.size() - 1].low;
        v2 = this->_vector_USDT_ETH[this->_vector_USDT_ETH.size() - (1 + this->_period)].low;
        r_low  = ((v1 * 100) / v2) - 100;

		this->_r_USDT_ETH = (r_high + r_low) / 2;
    }
	return this->_r_USDT_ETH;
}

int trade::calcul_s_USDT_ETH()
{
	this->_period;
    double moyenne1, temp1, moyenne2, temp2, s_high, s_low;
    moyenne1, moyenne2, temp1, temp2 = 0;
    if (this->_vector_USDT_ETH.size() > this->_period - 1){

        for (int i = this->_vector_USDT_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            moyenne1 += this->_vector_USDT_ETH[i].high;
        }
        moyenne1 /= this->_period;
        for (int i = this->_vector_USDT_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            temp1 += pow(this->_vector_USDT_ETH[i].high - moyenne1, 2);
        }

		for (int i = this->_vector_USDT_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            moyenne2 += this->_vector_USDT_ETH[i].low;
        }
        moyenne2 /= this->_period;
        for (int i = this->_vector_USDT_ETH.size() - 1, j = 0; j < this->_period; i--, j++){
            temp2 += pow(this->_vector_USDT_ETH[i].low - moyenne2, 2);
        }

		s_high = sqrt(temp1 / this->_period);
		s_low = sqrt(temp2 / this->_period);
		this->_s_USDT_ETH = (s_high + s_low) / 2;
    }
	return this->_s_USDT_ETH;
}

int trade::calcul_moy_USDT_ETH()
{
	double avg_high, avg_low, avg = 0;
	for (int i = 0; i < this->_vector_USDT_ETH.size(); i++){
		avg_high += this->_vector_USDT_ETH[i].close;
	}
	avg_high = avg_high / this->_vector_USDT_ETH.size();
	this->_m_USDT_ETH = avg_high;
	return avg;
}

int trade::receive(char *str)
{
    if (!str)
        return (-1);
    if (std::strcmp(str, "settings") == 0)
        return (0);
    if (std::strcmp(str, "update") == 0)
        return (1);
    if (std::strcmp(str, "action") == 0)
        return (2);
    return (-1);
}

void trade::stacks()
{
	std::string num;
	std::string BTC;
	std::string ETC;
	std::string USTD;
	int a = 0;

	num = _InputStr[3].c_str();
	for (; num[a] != ','; a++) {
		if (num[a] != 'B' && num[a] != 'T' && num[a] != 'C' && num[a] != ':')
			BTC.push_back(num[a]);
	}
	a++;
	for (; num[a] != ','; a++) {
		if (num[a] != 'E' && num[a] != 'T' && num[a] != 'H' && num[a] != ':')
			ETC.push_back(num[a]);
	}
	a++;
	for (; num[a]; a++) {
		if (num[a] != 'U' && num[a] != 'S' && num[a] != 'D' && num[a] != 'T' && num[a] != ':')
			USTD.push_back(num[a]);
	}
	_BTC = atof(BTC.c_str());
	_ETH = atof(ETC.c_str());
	_USDT = atof(USTD.c_str());
}

void trade::follow_BTC_ETH()
{
	std::string num;
	std::string value;
	int a = 0;

	num = _InputStr[3].c_str();
	for (; num[a] != ','; a++);
	a++;
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_BTC_ETH.date = atoi(value.c_str());
	value.clear();
	a++;
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_BTC_ETH.high = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_BTC_ETH.low = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_BTC_ETH.open = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_BTC_ETH.close = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ';' || !num[a] ; a++)
		value.push_back(num[a]);
	_BTC_ETH.volume = (atof(value.c_str()));
	_vector_BTC_ETH.push_back(_BTC_ETH);
	this->_period++;
}

void trade::follow_USDT_ETH()
{
	std::string num;
	std::string value;
	int a = 0;

	num = _InputStr[3].c_str();
	for (; num[a] != ','; a++);
	a++;
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_ETH.date = atoi(value.c_str());
	value.clear();
	a++;
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_ETH.high = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_ETH.low = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_ETH.open = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_ETH.close = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ';' || !num[a] ; a++)
		value.push_back(num[a]);
	_USDT_ETH.volume = (atof(value.c_str()));
	_vector_USDT_ETH.push_back(_USDT_ETH);
}

void trade::follow_USDT_BTC()
{
	std::string num;
	std::string value;
	int a = 0;

	num = _InputStr[3].c_str();
	for (; num[a] != ','; a++);
	a++;
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_BTC.date = atoi(value.c_str());
	value.clear();
	a++;
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_BTC.high = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_BTC.low = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_BTC.open = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ','; a++)
		value.push_back(num[a]);
	_USDT_BTC.close = (atof(value.c_str()));
	a++;
	value.clear();
	for (; num[a] != ';' || !num[a] ; a++)
		value.push_back(num[a]);
	_USDT_BTC.volume = (atof(value.c_str()));
	_vector_USDT_BTC.push_back(_USDT_BTC);
}

void trade::next_candles()
{
	std::string num;
	std::string value;
	char *tabOfCommand[4];

	num = _InputStr[3].c_str();
	tabOfCommand[0] = strtok((char *)num.c_str(), ";");
	tabOfCommand[1] = strtok(NULL, ";");
	tabOfCommand[2] = strtok(NULL, ";");
	tabOfCommand[3] = NULL;
	for (int i = 0; tabOfCommand[i]; i++) {
		for (int a = 0; tabOfCommand[i][a] != ','; a++) {
			value.push_back(tabOfCommand[i][a]);
		}
		if (!strcmp(value.c_str(), "BTC_ETH"))
			follow_BTC_ETH();
		if (!strcmp(value.c_str(), "USDT_ETH"))
			follow_USDT_ETH();
		if (!strcmp(value.c_str(), "USDT_BTC"))
			follow_USDT_BTC();
		value.clear();
	}
}

void trade::parser_update()
{
	if (!std::strcmp(_InputStr[2].c_str(), "stacks")) {
		stacks();
	}
	if (!std::strcmp(_InputStr[2].c_str(), "next_candles")) {
		next_candles();
	}

}

void trade::setting()
{
	//std::cout << "pass" << std::endl;
}

void trade::update()
{
	parser_update();
}

void trade::action()
{

}

void trade::buy_or_sell()
{
	int i = 0;
	long double amont_BTC_ETH = 1;
	long double amont_USDT_BTC = 1;
	long double amont_USDT_ETH = 1;

	long double BTC_ETH_value = this->_BTC_ETH.close;
	long double USDT_BTC_value = this->_USDT_BTC.close;
	long double USDT_ETH_value = this->_USDT_ETH.close;

	long double btc_eth = BTC_ETH_value - this->_m_BTC_ETH;
	long double usdt_btc = USDT_BTC_value - this->_m_USDT_BTC;
	long double usdt_eth = USDT_ETH_value - this->_m_USDT_ETH;

	if (abs(btc_eth) > abs(usdt_btc) && abs(btc_eth) > abs(usdt_eth)){
		if (btc_eth < 0){
			if (_BTC >= _BTC_ETH.close) {
				std::cout << "buy BTC_ETH " << amont_BTC_ETH << std::endl;
			} else {
				while (amont_BTC_ETH > _BTC_ETH.close)
					amont_BTC_ETH -= 0.1;
				std::cout << "buy BTC_ETH " << amont_BTC_ETH << std::endl;
			}
		} else if(btc_eth > 0 && _ETH > 0){
			std::cout << "sell BTC_ETH " << _ETH <<std::endl;
		} else {
			std::cout << "pass" << std::endl;
		}
	}

	if (abs(usdt_btc) > abs(usdt_eth) && abs(usdt_btc) > abs(btc_eth)){
		if (usdt_btc < 0){
			if (_USDT >= _USDT_BTC.close) {
				std::cout << "buy USDT_BTC " << amont_USDT_BTC << std::endl;
			} else {
				while (amont_USDT_BTC > _USDT_BTC.close)
					amont_USDT_BTC -= 0.1;
				std::cout << "buy USDT_BTC " << amont_USDT_BTC << std::endl;
			}
		} else if(usdt_btc > 0 && _BTC > 0){
			std::cout << "sell USDT_BTC "<< _BTC <<std::endl;
		} else {
			std::cout << "pass" << std::endl;
		}
	}

	if (abs(usdt_eth) > abs(usdt_btc) && abs(usdt_eth) > abs(btc_eth)){
		if (usdt_eth < 0){
			if (_USDT >= _USDT_ETH.close) {
				std::cout << "buy USDT_ETH " << amont_USDT_ETH << std::endl;
			} else {
				while (amont_USDT_ETH > _USDT_ETH.close)
					amont_USDT_ETH -= 0.1;
				std::cout << "buy USDT_ETH " << amont_USDT_ETH << std::endl;
			}
		} else if(usdt_eth > 0 && _ETH > 0){
			std::cout << "sell USDT_ETH" << _ETH << std::endl;
		} else {
			std::cout << "pass" << std::endl;
		}
	}

}

void trade::loop()
{
	std::string str;
	int ret;
	while (std::getline(std::cin, str)) {
		char *save_value = std::strtok((char *)str.c_str(), " ");
		while(save_value != NULL) {
			_InputStr.push_back(save_value);
			save_value = std::strtok(NULL, " ");
		}

		ret = receive((char *)_InputStr[0].c_str());	

		if (ret == 0)
			setting();
		else if (ret == 1)
			update();
		else if (ret == 2)
			action();
		else
			exit(-1);
		_InputStr.clear();

		if (this->_period > 0){
			calcul_g_BTC_ETH();
			calcul_r_BTC_ETH();
			calcul_s_BTC_ETH();
			calcul_moy_BTC_ETH();
			calcul_g_USDT_BTC();
			calcul_r_USDT_BTC();
			calcul_s_USDT_BTC();
			calcul_moy_USDT_BTC();
			calcul_g_USDT_ETH();
			calcul_r_USDT_ETH();
			calcul_s_USDT_ETH();
			calcul_moy_USDT_ETH();

			buy_or_sell();
		}
	}
}

int main ()
{
	trade usage;
	usage.loop();
	return (0);
}