#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the type of a SV.
    /// Satellite SV ID accepted values:
    /// QZSS 1..10
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// System string Only "QZSS" supported.
    /// SvId   int    Satellite SV ID, see command description for accepted values.
    ///

    class GetSVType;
    typedef std::shared_ptr<GetSVType> GetSVTypePtr;
    
    
    class GetSVType : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSVType();

      GetSVType(const std::string& system, int svId);

      static GetSVTypePtr create(const std::string& system, int svId);
      static GetSVTypePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

