
#include "Quit.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of Quit
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Quit::CmdName = "Quit";
    const char* const Quit::Documentation = "Quit/Exit Skydel. Simulation must be stopped to be able to quit Skydel\n"
      "\n"
      "Name      Type Description\n"
      "--------- ---- --------------------------------------------------------\n"
      "ForceQuit bool Force to quit Skydel even if current config is not saved";
    const char* const Quit::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Quit);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Quit);


    Quit::Quit()
      : CommandBase(CmdName, TargetId)
    {}

    Quit::Quit(bool forceQuit)
      : CommandBase(CmdName, TargetId)
    {

      setForceQuit(forceQuit);
    }

    QuitPtr Quit::create(bool forceQuit)
    {
      return std::make_shared<Quit>(forceQuit);
    }

    QuitPtr Quit::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Quit>(ptr);
    }

    bool Quit::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["ForceQuit"])
        ;

    }

    std::string Quit::documentation() const { return Documentation; }

    const std::vector<std::string>& Quit::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ForceQuit"}; 
      return names; 
    }


    int Quit::executePermission() const
    {
      return EXECUTE_IF_NO_CONFIG | EXECUTE_IF_IDLE;
    }


    bool Quit::forceQuit() const
    {
      return parse_json<bool>::parse(m_values["ForceQuit"]);
    }

    void Quit::setForceQuit(bool forceQuit)
    {
      m_values.AddMember("ForceQuit", parse_json<bool>::format(forceQuit, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
