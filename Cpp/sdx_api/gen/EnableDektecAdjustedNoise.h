#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Adjusts the Advanced Jammer IQ data amplitude on the Dektec output by adding noise to ensure power level linearity on weak jammer signals. Note that enabling this option will increase the noise observed at the RF output for all jammer signal power levels.
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------------
    /// Enable bool True to enable Advance Jammer noise adjustment on Dektec output.
    ///

    class EnableDektecAdjustedNoise;
    typedef std::shared_ptr<EnableDektecAdjustedNoise> EnableDektecAdjustedNoisePtr;
    
    
    class EnableDektecAdjustedNoise : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableDektecAdjustedNoise();

      EnableDektecAdjustedNoise(bool enable);

      static EnableDektecAdjustedNoisePtr create(bool enable);
      static EnableDektecAdjustedNoisePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enable ****
      bool enable() const;
      void setEnable(bool enable);
    };
    
  }
}

