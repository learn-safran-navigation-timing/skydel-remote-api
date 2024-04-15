#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the type of a SV.
    /// Satellite SV ID accepted values (0 for all SVs):
    /// QZSS 1..10
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// System string Only "QZSS" supported.
    /// SvId   int    Satellite SV ID, see command description for accepted values.
    /// SvType string Type of the SV. QZSS: "BlockI", "BlockII".
    ///

    class SetSVType;
    typedef std::shared_ptr<SetSVType> SetSVTypePtr;
    
    
    class SetSVType : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSVType();

      SetSVType(const std::string& system, int svId, const std::string& svType);

      static SetSVTypePtr create(const std::string& system, int svId, const std::string& svType);
      static SetSVTypePtr dynamicCast(CommandBasePtr ptr);
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


      // **** svType ****
      std::string svType() const;
      void setSvType(const std::string& svType);
    };
    
  }
}

