#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Delete a space vehicle antenna model. The default SV antenna model can't be deleted.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// Name   string SV antenna model name
    /// System string "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS", "NavIC" or "PULSAR"
    ///

    class DeleteSVAntennaModel;
    typedef std::shared_ptr<DeleteSVAntennaModel> DeleteSVAntennaModelPtr;
    
    
    class DeleteSVAntennaModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      DeleteSVAntennaModel();

      DeleteSVAntennaModel(const std::string& name, const std::string& system);

      static DeleteSVAntennaModelPtr create(const std::string& name, const std::string& system);
      static DeleteSVAntennaModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** name ****
      std::string name() const;
      void setName(const std::string& name);


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);
    };
    
  }
}

