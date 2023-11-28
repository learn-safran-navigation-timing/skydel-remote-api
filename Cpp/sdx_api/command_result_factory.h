#ifndef COMMAND_RESULT_FACTORY_H
#define COMMAND_RESULT_FACTORY_H

#include <string>

#include "command_result.h"

#define REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(COMMAND_CLASS_NAME)                                           \
  inline CommandResultPtr functionToCreateCommand##COMMAND_CLASS_NAME()                                       \
  {                                                                                                           \
    return std::make_shared<COMMAND_CLASS_NAME>();                                                            \
  }                                                                                                           \
  class ClassToRegisterCommand##COMMAND_CLASS_NAME                                                            \
  {                                                                                                           \
  public:                                                                                                     \
    ClassToRegisterCommand##COMMAND_CLASS_NAME()                                                              \
    {                                                                                                         \
      CommandResultFactory::instance()->registerFactoryFunction(COMMAND_CLASS_NAME::CmdName,                  \
                                                                functionToCreateCommand##COMMAND_CLASS_NAME); \
    }                                                                                                         \
  };                                                                                                          \
  ClassToRegisterCommand##COMMAND_CLASS_NAME functionToCreateInstanceToRegisterCommand##COMMAND_CLASS_NAME(); \
  namespace                                                                                                   \
  {                                                                                                           \
  ClassToRegisterCommand##COMMAND_CLASS_NAME instanceToRegisterCommand##COMMAND_CLASS_NAME =                  \
    functionToCreateInstanceToRegisterCommand##COMMAND_CLASS_NAME();                                          \
  }

#define REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(COMMAND_CLASS_NAME)                                          \
  ClassToRegisterCommand##COMMAND_CLASS_NAME functionToCreateInstanceToRegisterCommand##COMMAND_CLASS_NAME() \
  {                                                                                                          \
    static ClassToRegisterCommand##COMMAND_CLASS_NAME staticInstance;                                        \
    return staticInstance;                                                                                   \
  }

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
