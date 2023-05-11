
#include "gen/Quit.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of Quit
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Quit::CmdName = "Quit";
    const char* const Quit::Documentation = "Quit/Exit Skydel. Simulation must be stopped to be able to quit Skydel";

    REGISTER_COMMAND_FACTORY(Quit);


    Quit::Quit()
      : CommandBase(CmdName)
    {}

    Quit::Quit(bool forceQuit)
      : CommandBase(CmdName)
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
