//Neural Net
#include <vector>
#include <iostream>

using namespace std;

class Neuron{};

typedef vector<Neuron> Layer;

class Net
{
public:
	Net(const vector<unsigned> &topology);
	void feedForward(const vector<double> &inputVals){};
	void backProp(const vector<double> &targetVals){};
	void getResults(vector<double> &resultsVals) const{};

private:
	vector<Layer> m_layers;//[layerNum][neuronNum]
};

Net::Net(const vector<unsigned> &topology)
{
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		m_layers.push_back(Layer());

		//We made a new layer, now fill it with neurons
		//annd a bias neuron to the layer
		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
		{
			m_layers.back().push_back(Neuron());
			cout << "Made a Neuron!" << endl;
		}
	}
}

int main()
{
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	vector<double> inputVals;
	myNet.feedForward(inputVals);

	vector<double> targetVals;
	myNet.backProp(targetVals);

	vector<double> resultVals;
	myNet.getResults(resultVals);

	return 0;
}