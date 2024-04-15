
#include "GetOsnmaTagSizeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetOsnmaTagSizeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetOsnmaTagSizeResult::CmdName = "GetOsnmaTagSizeResult";
    const char* const GetOsnmaTagSizeResult::Documentation = "Result of GetOsnmaTagSize.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- ----------------------------------------------------------------\n"
      "TagSize int  Tag size in bits. Accepted tag sizes are: 20, 24, 28, 32 and 40.";
    const char* const GetOsnmaTagSizeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetOsnmaTagSizeResult);


    GetOsnmaTagSizeResult::GetOsnmaTagSizeResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetOsnmaTagSizeResult::GetOsnmaTagSizeResult(int tagSize)
      : CommandResult(CmdName, TargetId)
    {

      setTagSize(tagSize);
    }

    GetOsnmaTagSizeResult::GetOsnmaTagSizeResult(CommandBasePtr relatedCommand, int tagSize)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setTagSize(tagSize);
    }


    GetOsnmaTagSizeResultPtr GetOsnmaTagSizeResult::create(int tagSize)
    {
      return std::make_shared<GetOsnmaTagSizeResult>(tagSize);
    }

    GetOsnmaTagSizeResultPtr GetOsnmaTagSizeResult::create(CommandBasePtr relatedCommand, int tagSize)
    {
      return std::make_shared<GetOsnmaTagSizeResult>(relatedCommand, tagSize);
    }

    GetOsnmaTagSizeResultPtr GetOsnmaTagSizeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetOsnmaTagSizeResult>(ptr);
    }

    bool GetOsnmaTagSizeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["TagSize"])
        ;

    }

    std::string GetOsnmaTagSizeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetOsnmaTagSizeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"TagSize"}; 
      return names; 
    }


    int GetOsnmaTagSizeResult::tagSize() const
    {
      return parse_json<int>::parse(m_values["TagSize"]);
    }

    void GetOsnmaTagSizeResult::setTagSize(int tagSize)
    {
      m_values.AddMember("TagSize", parse_json<int>::format(tagSize, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
