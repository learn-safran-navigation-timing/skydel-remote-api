
#include "SetHilTjoin.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetHilTjoin
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetHilTjoin::CmdName = "SetHilTjoin";
    const char* const SetHilTjoin::Documentation = "HIL Tjoin. Value is in milliseconds.\n"
      "\n"
      "Name     Type Description\n"
      "-------- ---- -----------\n"
      "HilTjoin int  HIL Tjoin.";
    const char* const SetHilTjoin::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetHilTjoin);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetHilTjoin);


    SetHilTjoin::SetHilTjoin()
      : CommandBase(CmdName, TargetId)
    {}

    SetHilTjoin::SetHilTjoin(int hilTjoin)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetHilTjoin::fieldNames() const 
    { 
      static const std::vector<std::string> names {"HilTjoin"}; 
      return names; 
    }


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
