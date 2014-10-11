/*
 * LayerControl.h
 *
 *  Created on: 25 May 2013
 *      Author: robert
 */

#ifndef LAYERCONTROL_H_
#define LAYERCONTROL_H_

class LayerControl {

public:
	LayerControl();
	virtual ~LayerControl();

	void off();
	void on(int layer);
};


#endif /* LAYERCONTROL_H_ */
