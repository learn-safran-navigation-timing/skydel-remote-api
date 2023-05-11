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
    /// Result of GetSVType.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// System string Only "QZSS" supported.
    /// SvId   int    Satellite SV ID, see command description for accepted values.
    /// SvType string Type of the SV. QZSS: "BlockI", "BlockII".
    ///

    class GetSVTypeResult;
    typedef std::shared_ptr<GetSVTypeResult> GetSVTypeResultPtr;
    
    
    class GetSVTypeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVTypeResult();

      GetSVTypeResult(const std::string& system, int svId, const std::string& svType);

      GetSVTypeResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& svType);

      static GetSVTypeResultPtr create(const std::string& system, int svId, const std::string& svType);

      static GetSVTypeResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::string& svType);
      static GetSVTypeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** svType ****
      std::string svType() const;
      void setSvType(const std::string& svType);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSVTypeResult);
  }
}

