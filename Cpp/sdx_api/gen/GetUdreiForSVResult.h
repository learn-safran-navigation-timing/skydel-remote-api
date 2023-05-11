#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetUdreiForSV.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------------------
    /// System string "GPS" or "SBAS".
    /// SvId   int    The satellite's SV ID (use 0 to apply modification to all SVs).
    /// Udrei  int    The UDREI value.
    ///

    class GetUdreiForSVResult;
    typedef std::shared_ptr<GetUdreiForSVResult> GetUdreiForSVResultPtr;
    
    
    class GetUdreiForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetUdreiForSVResult();

      GetUdreiForSVResult(const std::string& system, int svId, int udrei);

      GetUdreiForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei);

      static GetUdreiForSVResultPtr create(const std::string& system, int svId, int udrei);

      static GetUdreiForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, int udrei);
      static GetUdreiForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** udrei ****
      int udrei() const;
      void setUdrei(int udrei);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetUdreiForSVResult);
  }
}

