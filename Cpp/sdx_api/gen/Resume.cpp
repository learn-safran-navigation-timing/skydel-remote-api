
#include "gen/Resume.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of Resume
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Resume::CmdName = "Resume";
    const char* const Resume::Documentation = "Resume vehicle motion during simulation.";

    REGISTER_COMMAND_FACTORY(Resume);


    Resume::Resume()
      : CommandBase(CmdName)
    {

    }

    ResumePtr Resume::create()
    {
      return std::make_shared<Resume>();
    }

    ResumePtr Resume::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Resume>(ptr);
    }

    bool Resume::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string Resume::documentation() const { return Documentation; }


    int Resume::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
