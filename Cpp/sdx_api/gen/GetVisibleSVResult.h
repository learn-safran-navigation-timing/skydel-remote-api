#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetVisibleSV.
    ///
    /// Name   Type      Description
    /// ------ --------- -----------------------------------------------------------------------------------
    /// System string    The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   array int A list containing the visible satellites' SV IDs
    ///

    class GetVisibleSVResult;
    typedef std::shared_ptr<GetVisibleSVResult> GetVisibleSVResultPtr;
    
    
    class GetVisibleSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetVisibleSVResult();

      GetVisibleSVResult(const std::string& system, const std::vector<int>& svId);

      GetVisibleSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& svId);

      static GetVisibleSVResultPtr create(const std::string& system, const std::vector<int>& svId);

      static GetVisibleSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& svId);
      static GetVisibleSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      std::vector<int> svId() const;
      void setSvId(const std::vector<int>& svId);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetVisibleSVResult);
  }
}

