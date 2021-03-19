#ifndef COMMAND_RESULT_FACTORY_H
#define COMMAND_RESULT_FACTORY_H

#include "command_result.h"
#include <string>

#define REGISTER_COMMAND_RESULT_FACTORY(COMMAND_CLASS_NAME) \
CommandResultPtr functionToCreateCommand##COMMAND_CLASS_NAME() {\
  return CommandResultPtr(new COMMAND_CLASS_NAME); \
} \
class ClassToRegisterCommand##COMMAND_CLASS_NAME { \
public: \
  ClassToRegisterCommand##COMMAND_CLASS_NAME() { \
    CommandResultFactory::instance()->registerFactoryFunction(COMMAND_CLASS_NAME::CmdName, functionToCreateCommand##COMMAND_CLASS_NAME); \
  } \
}; \
ClassToRegisterCommand##COMMAND_CLASS_NAME instanceToRegisterCommand##COMMAND_CLASS_NAME


namespace Sdx
{

class CommandResultFactory
{
public:
  static CommandResultFactory* instance();
  ~CommandResultFactory();
  CommandResultPtr createCommandResult(const std::string& serializedCommand, std::string* errorMsg = 0);
  typedef CommandResultPtr (*FactoryFunction)();
  void registerFactoryFunction(const std::string& cmdName, FactoryFunction);
private:
  CommandResultFactory();
  struct Pimpl;
  Pimpl* m;
};

} // namespace Sdx


#endif // COMMAND_RESULT_FACTORY_H
