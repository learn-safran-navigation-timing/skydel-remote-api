
#include "SetOsnmaTagSize.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetOsnmaTagSize
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetOsnmaTagSize::CmdName = "SetOsnmaTagSize";
    const char* const SetOsnmaTagSize::Documentation = "Set OSNMA tag size.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------\n"
      "TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.";
    const char* const SetOsnmaTagSize::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetOsnmaTagSize);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetOsnmaTagSize);


    SetOsnmaTagSize::SetOsnmaTagSize()
      : CommandBase(CmdName, TargetId)
    {}

    SetOsnmaTagSize::SetOsnmaTagSize(int tagSize)
      : CommandBase(CmdName, TargetId)
    {

      setTagSize(tagSize);
    }

    SetOsnmaTagSizePtr SetOsnmaTagSize::create(int tagSize)
    {
      return std::make_shared<SetOsnmaTagSize>(tagSize);
    }

    SetOsnmaTagSizePtr SetOsnmaTagSize::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetOsnmaTagSize>(ptr);
    }

    bool SetOsnmaTagSize::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["TagSize"])
        ;

    }

    std::string SetOsnmaTagSize::documentation() const { return Documentation; }

    const std::vector<std::string>& SetOsnmaTagSize::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TagSize"}; 
      return names; 
    }


    int SetOsnmaTagSize::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetOsnmaTagSize::tagSize() const
    {
      return parse_json<int>::parse(m_values["TagSize"]);
    }

    void SetOsnmaTagSize::setTagSize(int tagSize)
    {
      m_values.AddMember("TagSize", parse_json<int>::format(tagSize, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
