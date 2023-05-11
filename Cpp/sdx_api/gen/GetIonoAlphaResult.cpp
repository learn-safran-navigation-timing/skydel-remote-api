
#include "gen/GetIonoAlphaResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoAlphaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoAlphaResult::CmdName = "GetIonoAlphaResult";
    const char* const GetIonoAlphaResult::Documentation = "Result of GetIonoAlpha.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIonoAlphaResult);


    GetIonoAlphaResult::GetIonoAlphaResult()
      : CommandResult(CmdName)
    {}

    GetIonoAlphaResult::GetIonoAlphaResult(int index, double val)
      : CommandResult(CmdName)
    {

      setIndex(index);
      setVal(val);
    }

    GetIonoAlphaResult::GetIonoAlphaResult(CommandBasePtr relatedCommand, int index, double val)
      : CommandResult(CmdName, relatedCommand)
    {

      setIndex(index);
      setVal(val);
    }


    GetIonoAlphaResultPtr GetIonoAlphaResult::create(int index, double val)
    {
      return std::make_shared<GetIonoAlphaResult>(index, val);
    }

    GetIonoAlphaResultPtr GetIonoAlphaResult::create(CommandBasePtr relatedCommand, int index, double val)
    {
      return std::make_shared<GetIonoAlphaResult>(relatedCommand, index, val);
    }

    GetIonoAlphaResultPtr GetIonoAlphaResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoAlphaResult>(ptr);
    }

    bool GetIonoAlphaResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string GetIonoAlphaResult::documentation() const { return Documentation; }


    int GetIonoAlphaResult::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void GetIonoAlphaResult::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIonoAlphaResult::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void GetIonoAlphaResult::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
