
#include "SetUsingVelocityInSbasMessage25.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetUsingVelocityInSbasMessage25
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetUsingVelocityInSbasMessage25::CmdName = "SetUsingVelocityInSbasMessage25";
    const char* const SetUsingVelocityInSbasMessage25::Documentation = "Set whether SBAS message 25 should send velocity corrections\n"
      "\n"
      "Name        Type Description\n"
      "----------- ---- --------------------------------------------------------\n"
      "UseVelocity bool Whether SBAS message 25 should send velocity corrections";
    const char* const SetUsingVelocityInSbasMessage25::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetUsingVelocityInSbasMessage25);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetUsingVelocityInSbasMessage25);


    SetUsingVelocityInSbasMessage25::SetUsingVelocityInSbasMessage25()
      : CommandBase(CmdName, TargetId)
    {}

    SetUsingVelocityInSbasMessage25::SetUsingVelocityInSbasMessage25(bool useVelocity)
      : CommandBase(CmdName, TargetId)
    {

      setUseVelocity(useVelocity);
    }

    SetUsingVelocityInSbasMessage25Ptr SetUsingVelocityInSbasMessage25::create(bool useVelocity)
    {
      return std::make_shared<SetUsingVelocityInSbasMessage25>(useVelocity);
    }

    SetUsingVelocityInSbasMessage25Ptr SetUsingVelocityInSbasMessage25::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetUsingVelocityInSbasMessage25>(ptr);
    }

    bool SetUsingVelocityInSbasMessage25::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["UseVelocity"])
        ;

    }

    std::string SetUsingVelocityInSbasMessage25::documentation() const { return Documentation; }

    const std::vector<std::string>& SetUsingVelocityInSbasMessage25::fieldNames() const 
    { 
      static const std::vector<std::string> names {"UseVelocity"}; 
      return names; 
    }


    int SetUsingVelocityInSbasMessage25::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool SetUsingVelocityInSbasMessage25::useVelocity() const
    {
      return parse_json<bool>::parse(m_values["UseVelocity"]);
    }

    void SetUsingVelocityInSbasMessage25::setUseVelocity(bool useVelocity)
    {
      m_values.AddMember("UseVelocity", parse_json<bool>::format(useVelocity, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
