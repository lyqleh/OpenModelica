#pragma once

#define LOADER_SUCCESS                      ( 0  )
#define LOADER_ERROR                        ( -1 )
#define LOADER_ERROR_UNDEFINED_REFERENCES   ( -2 )
#define LOADER_ERROR_FILE_NOT_FOUND         ( -3 )
#define LOADER_ERROR_FUNC_NOT_FOUND         ( -4 )
typedef int LOADERRESULT;
class ISimController;
struct SimSettings;
class OMCFactory
{
    public:
    OMCFactory();
        OMCFactory(PATH library_path, PATH modelicasystem_path);
        virtual ~OMCFactory();
        void UnloadAllLibs(void);
        LOADERRESULT LoadLibrary(string libName,type_map& current_map);
        LOADERRESULT UnloadLibrary(shared_library lib);

        virtual std::pair<boost::shared_ptr<ISimController>,SimSettings> createSimulation(int argc,  const char* argv[]);

    protected:

        SimSettings ReadSimulationParameter(int argc, const char* argv[]);
        boost::shared_ptr<ISimController> _simController;
        std::map<string,shared_library> _modules;
        PATH _library_path;
        PATH _modelicasystem_path;
};


