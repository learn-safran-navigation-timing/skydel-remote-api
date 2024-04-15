
#include "GetIonoAlphaResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoAlphaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoAlphaResult::CmdName = "GetIonoAlphaResult";
    const char* const GetIonoAlphaResult::Documentation = "Result of GetIonoAlpha.\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------\n"
      "Index int    Coefficient index [0..3]\n"
      "Val   double Coefficient value";
    const char* const GetIonoAlphaResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoAlphaResult);


    GetIonoAlphaResult::GetIonoAlphaResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIonoAlphaResult::GetIonoAlphaResult(int index, double val)
      : CommandResult(CmdName, TargetId)
    {

      setIndex(index);
      setVal(val);
    }

    GetIonoAlphaResult::GetIonoAlphaResult(CommandBasePtr relatedCommand, int index, double val)
      : CommandResult(CmdName, TargetId, relatedCommand)
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

    const std::vector<std::string>& GetIonoAlphaResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index", "Val"}; 
      return names; 
    }


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
