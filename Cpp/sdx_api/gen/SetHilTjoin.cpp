
#include "gen/SetHilTjoin.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetHilTjoin
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetHilTjoin::CmdName = "SetHilTjoin";
    const char* const SetHilTjoin::Documentation = "HIL Tjoin. Value is in milliseconds.";

    REGISTER_COMMAND_FACTORY(SetHilTjoin);


    SetHilTjoin::SetHilTjoin()
      : CommandBase(CmdName)
    {}

    SetHilTjoin::SetHilTjoin(int hilTjoin)
      : CommandBase(CmdName)
    {

      setHilTjoin(hilTjoin);
    }

    SetHilTjoinPtr SetHilTjoin::create(int hilTjoin)
    {
      return std::make_shared<SetHilTjoin>(hilTjoin);
    }

    SetHilTjoinPtr SetHilTjoin::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetHilTjoin>(ptr);
    }

    bool SetHilTjoin::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["HilTjoin"])
        ;

    }

    std::string SetHilTjoin::documentation() const { return Documentation; }


    int SetHilTjoin::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetHilTjoin::hilTjoin() const
    {
      return parse_json<int>::parse(m_values["HilTjoin"]);
    }

    void SetHilTjoin::setHilTjoin(int hilTjoin)
    {
      m_values.AddMember("HilTjoin", parse_json<int>::format(hilTjoin, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
