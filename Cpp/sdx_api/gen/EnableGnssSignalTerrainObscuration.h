#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) GNSS signals obscuration by terrain.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------
    /// Enabled bool If true, GNSS signals from satellites obscured by terrain will not reach the receiver.
    ///

    class EnableGnssSignalTerrainObscuration;
    typedef std::shared_ptr<EnableGnssSignalTerrainObscuration> EnableGnssSignalTerrainObscurationPtr;
    
    
    class EnableGnssSignalTerrainObscuration : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableGnssSignalTerrainObscuration();

      EnableGnssSignalTerrainObscuration(bool enabled);

      static EnableGnssSignalTerrainObscurationPtr create(bool enabled);
      static EnableGnssSignalTerrainObscurationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

